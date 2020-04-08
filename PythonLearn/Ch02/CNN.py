from matplotlib import pyplot
from matplotlib import cm
import torch
import torch.nn as nn
import torchvision
import numpy as np
import scipy
import os

EPOCH = 1
BATCH_SIZE = 50
LR = 0.001
DOWNLOAD_MNIST = False

if not(os.path.exists('./mnist/')) or not os.listdir('./mnist/'):
    DOWNLOAD_MNIST = True

train_data = torchvision.datasets.MNIST(
    root='./mnist/',
    train=True,
    transform=torchvision.transforms.ToTensor(),
    download=DOWNLOAD_MNIST,
)

train_loader = torch.utils.data.DataLoader(
    dataset=train_data, batch_size=BATCH_SIZE, shuffle=True)

test_data = torchvision.datasets.MNIST(root='./mnist',
                                       train=False)
test_x = torch.unsqueeze(test_data.test_data, dim=1).type(
    torch.FloatTensor)[:2000]/255.

test_y = test_data.test_labels[:2000]


class CNN(nn.Module):
    def __init__(self):
        super(CNN, self).__init__()
        self.conv1 = nn.Sequential(
            nn.Conv2d(
                in_channels=1,
                out_channels=16,
                kernel_size=5,
                stride=1,
                padding=2,
            ),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2),
        )
        self.conv2 = nn.Sequential(
            nn.Conv2d(in_channels=16, out_channels=32,
                      kernel_size=5, padding=2, stride=1),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2),

        )

        self.out = nn.Linear(in_features=32*7*7, out_features=10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.conv2(x)
        x = x.view(size=(x.size(0),-1))
        output = self.out(x)

        return output, x


cnn = CNN()
print(cnn)

optimizer = torch.optim.Adam(cnn.parameters(), lr=LR)

loss_func = nn.CrossEntropyLoss()


try:
    from sklearn.manifold import TSNE
    HAS_SK = True
except:
    HAS_SK = False
    print('please install sklearn for layer visualization')


def plot_with_labels(lowDWeights, labels):
    pyplot.cla()
    X, Y = lowDWeights[:, 0], lowDWeights[:, 1]

    for x, y, s in zip(X, Y, labels):
        c = cm.rainbow(int(255*s/9))
        pyplot.text(x, y, s, backgroundcolor=c, fontsize=9)

    pyplot.xlim(X.min(), X.max())
    pyplot.ylim(Y.min(), Y.max())
    pyplot.title('Visualize last layer')
    pyplot.show()
    pyplot.pause(0.01)


pyplot.ion()

for epoch in range(EPOCH):
    for step, (b_x, b_y) in enumerate(train_loader):

        output = cnn(b_x)[0]
        loss = loss_func(input=output, target=b_y)
        optimizer.zero_grad()

        loss.backward()

        optimizer.step()

        if step % 50 == 0:
            test_output, last_layer = cnn(test_x)
            pred_y = torch.max(test_output, dim=1)[1].data.numpy()
            accuracy = float((pred_y == test_y.data.numpy()).astype(
                int).sum()) / float(test_y.size(0))

            print('Epoch:', epoch, '| train loss:%.4f' % loss.data.numpy(), '| test accuracy:%.2f' % accuracy
                  )

            if HAS_SK:
                tsne = TSNE(perplexity=30,
                            n_components=2,
                            init='pca',
                            n_iter=5000,
                            )

                plot_only = 500
                low_dim_embs = tsne.fit_transform(
                    X=last_layer.data.numpy()[:plot_only, :])

                labels = test_y.numpy()[:plot_only]

                plot_with_labels(lowDWeights=low_dim_embs, labels=labels)

pyplot.ioff()

test_output, _ = cnn(test_x[:10])
pred_y = torch.max(test_output, 1)[1].data.numpy()

print(pred_y, 'prediction number')
print(test_y[:10].numpy(), 'real number')

