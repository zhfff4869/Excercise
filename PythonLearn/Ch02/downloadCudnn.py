import requests

URL1='https://developer.nvidia.com/compute/machine-learning/cudnn/secure/7.6.4.38/Production/10.1_20190923/cudnn-10.1-windows10-x64-v7.6.4.38.zip'
urls = [URL1,]
for url in urls:
    response = requests.get(url, stream=True)
    with open( './'+url.split('/')[-1], 'wb') as f:
        for chunk in response.iter_content(chunk_size=1024):
            if chunk:
                f.write(chunk)
