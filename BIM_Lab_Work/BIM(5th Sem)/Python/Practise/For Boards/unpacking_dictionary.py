def print_person(name, age, country):
    print(f"Name: {name}")
    print(f"Age: {age}")
    print(f"Country: {country}")


#Call the function with a packed dictionary of keyword arguments
person = {"name": "Ram", "age": 30, "country": "Nepal"}

print_person(**person)