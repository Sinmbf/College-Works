def pack_kwargs(**kwargs):
    print(kwargs)
    print(kwargs.items())

    for key, value in kwargs.items():
        print(f"{key} : {value}")


pack_kwargs(name="Ram", age=30, country="Nepal")