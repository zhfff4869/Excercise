
import scrapy
import re

# urladd=['http://www.tianqihoubao.com/lishi/longchang/month/%s.html' %i for i in range(j*100+1,j*100+13) for j in range(2011,2020)]

# urladd=[]
# for j in range(2011,2020):
#     urladd.extend(['http://www.tianqihoubao.com/lishi/longchang/month/%s.html' %i for i in range(j*100+1,j*100+13)])


class QuotesSpider(scrapy.Spider):
    name = "quotes"

    def start_requests(self):
        # urls=['http://www.tianqihoubao.com/lishi/longchang/month/%s.html' %i for i in range(201901,201913)]

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

        for url in urls:
            yield scrapy.Request(url=url, callback=self.parse)

    def parse(self, response):
        list=response.css('table.b').xpath('//tr[position()>1]/td[2]/text()').getall()  #得到
        filename = response.url.split("/")[-1].split(".")[0]
        with open(filename+".txt", 'w') as f:
            # f.write(list)
            for i in list:
                i=i.strip().split()
                add=i[0]+i[1]+' '
                f.write(add)
        self.log('Saved file %s' % filename)

