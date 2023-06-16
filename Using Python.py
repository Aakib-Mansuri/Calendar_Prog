calendar = {
    "Sun":[],
    "Mon":[],
    "Tue":[],
    "Wed":[],
    "Thus":[],
    "Fri":[],
    "Sat":[]
}

def isLeap(year):
    if (year%4 == 0 and year%100 != 0) or (year%400 == 0):
        return True
    return False


def getTotalLeap(year):
    dif = year - 1900
    leap = int(dif/4)
    if dif >= 200:
        leap += 1 #for 2000 which is leap
        leap -= int(dif/100) #every 100 years 1 leap less
    if (dif-100) >= 400:#100 for 2000 which is leap
        leap += int((dif-100)/400) #every 400 years 1 leap more
    return leap



def monthDays(month,year):
    if month in [1,3,5,7,8,10,12]:
        return 31
    elif month == 2:
        if isLeap(year):
            return 29
        else:
            return 28
    else:
        return 30


def getDay(month,year):
    leapYears = getTotalLeap(year)
    ordinaryYears = (year - 1900) - leapYears
    totalDays =  ordinaryYears * 365
    totalDays +=  leapYears * 366

    for i in range(1,month):
        totalDays += monthDays(i,year)

    return totalDays%7


year = int(input("Year: "))
month = int(input("Month: "))
day = list(calendar)[getDay(month,year)+1]
totMonDays = monthDays(month,year) 


counter = 1
bigFlag = 1
startFalg = 0

while bigFlag:
    for key in calendar.keys():
        if counter > totMonDays:
            bigFlag = 0
            calendar[key].append("")
            continue

        elif key != day and not startFalg:
            calendar[key].append("")

        else:
            startFalg = 1
            calendar[key].append(counter)
            counter += 1


for key in calendar.keys():
    print(key,end="\t")
    
for i in range(len(max(calendar.values(),key=len))):
    print("\n")
    for key in calendar.keys():
        print(calendar[key][i],end="\t")
