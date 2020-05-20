with open('weatherData1.txt','w') as f:
    with open('weatherData.txt','r') as r:
        list=r.read()
        list=list.split()
        for i in list:
            a=i.split('/')
            a=a[0]+a[1]+' '
            f.write(a)