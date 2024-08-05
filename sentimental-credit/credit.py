def get_ccn():
    ccn = input("Number: ")
    return ccn

def check_validation(listccn):
    check_odd_even = int(len(listccn) % 2)
    sum_not_doubled = 0
    sum_outlier = 0
    if check_odd_even == 0:
        product_stl = 0
        for i in range (0, len(listccn), 2):
            stl = int(listccn[i]) * 2
            if stl > 9:
                counter = 0
                while (counter != 2):
                    digit = stl % 10
                    sum_outlier = sum_outlier + digit
                    stl = stl // 10
                    counter += 1
            product_stl = product_stl + sum_outlier + stl
        for i in range (1, len(listccn), 2):
            sum_not_doubled = sum_not_doubled + int(listccn[i])
    else:
        product_stl = 0
        for i in range (1, len(listccn), 2):
            stl = int(listccn[i]) * 2
            if stl > 9:
                counter = 0
                while (counter != 2):
                    digit = stl % 10
                    sum_outlier = sum_outlier + digit
                    stl = stl // 10
                    counter += 1
            product_stl = product_stl + sum_outlier + stl
        for i in range (0, len(listccn), 2):
            sum_not_doubled = sum_not_doubled + int(listccn[i])


    validation = (sum_not_doubled + product_stl) % 10
    if (validation == 0):
        return True
    else:
        return False


def check_card(ccn):
    f2numbers = int(ccn[:2])
    status = check_validation(listccn)
    if status == False:
        print("INVALID")
    if status == True:
        if f2numbers == 32 or f2numbers == 37:
            print("AMEX")
        elif f2numbers >= 51 and f2numbers <= 55:
            print("MASTERCARD")
        elif f2numbers >= 40 and f2numbers <= 49:
            print("VISA")
        else:
            print("INVALID")


listccn = []
ccn = get_ccn()
for i in range(len(ccn)):
    listccn.append(ccn[i])

check_validation(listccn)
check_card(ccn)
