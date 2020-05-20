urls=[]
for j in range(2011,2020):
    urls.extend(['http://www.tianqihoubao.com/lishi/longchang/month/%s.html' %i for i in range(j*100+1,j*100+13)])
url2 = [
    'http://www.tianqihoubao.com/lishi/longchang/month/202001.html',
    'http://www.tianqihoubao.com/lishi/longchang/month/202002.html',
    'http://www.tianqihoubao.com/lishi/longchang/month/202003.html',
    'http://www.tianqihoubao.com/lishi/longchang/month/202004.html',
    'http://www.tianqihoubao.com/lishi/longchang/month/202005.html',
]
urls.extend(url2) #

for i in urls:
    print(i)