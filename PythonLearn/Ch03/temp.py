# url=['http://www.tianqihoubao.com/lishi/longchang/month/%s.html' %i for i in range(201901,201913)]
# print(url)

# urls = [
#     'http://www.tianqihoubao.com/lishi/longchang/month/202001.html',
#     'http://www.tianqihoubao.com/lishi/longchang/month/202002.html',
#     'http://www.tianqihoubao.com/lishi/longchang/month/202003.html',
#     'http://www.tianqihoubao.com/lishi/longchang/month/202004.html',
#     'http://www.tianqihoubao.com/lishi/longchang/month/202005.html',
# ]
# urls=urls.extend(url) 

# print(urls)

""" import re

s="\r\n小雨\r\n/晴天\r\n"
print(s.strip())
i=re.findall(r'\r\n(.*)\r\n(\/.*)\r',s)
print(i) """

with open("weatherData.txt",'ab') as f:
    for j in range(2011,2020):

        for i in range(j*100+1,j*100+13):
            f.write(open('./dataget/%s.txt'%i,'rb').read())
    for i in range(202001,202006):
        f.write(open('./dataget/%s.txt'%i,'rb').read())