import math

noOfCategories=int(input("Enter number of categories: "))
categories={}
total=0
print("Enter name of categories: ")
# Function to calculate price
def calculatePerPerson(price,noOfPerson,isPriceDifferent):
    remaining_price=price
    if isPriceDifferent:
        differentPrice=int(input("Enter price difference: "))
        remaining_price=price-differentPrice
    result= (math.ceil(remaining_price/noOfPerson)) 
    return result

# Function to show all category details
def showCategoryDetails(categoryObj):
    print(categoryObj["name"] + "\t\t\t\t\t\t\t\t\t" + str(categoryObj["price"]) + "\t\t" + str(categoryObj["noOfPerson"]))

# Take input
for i in range(noOfCategories):
    keyName="Category"+" " +str(i+1)
    categoryName=input(f"Category {i+1}: ")
    price=int(input("Price of this category: "))
    noOfPerson=int(input("No. of person: "))
    isPriceDifferent=bool(int(input("Is there price difference?[1/0]: ")))
    categories[keyName]={
        "name":categoryName,
        "price":price,
        "noOfPerson":noOfPerson,
        "isPriceDifferent":isPriceDifferent
    }

# Perform operations in categories
print("Name\t\t\t\t\t\t\t\t\tPrice\t\tNumber of Person")
for categoryNo,categoryObj in categories.items():
    showCategoryDetails(categoryObj)                
    priceForOneCategory=calculatePerPerson(categoryObj["price"],categoryObj["noOfPerson"],categoryObj["isPriceDifferent"])
    total+=priceForOneCategory
print(f"Total price per person: {total}")