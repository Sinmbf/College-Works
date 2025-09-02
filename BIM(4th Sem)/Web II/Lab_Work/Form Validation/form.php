<?php
$nameErr = $emailErr = $phoneErr = $passwordErr = "";
$name = $email = $phoneNum = $password = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
        $nameErr = "Name is required";
    } else {
        $name = $_POST["name"];
        if (!preg_match("/^[a-zA-Z ]*$/", $name)) {
            $nameErr = "Only alphabets and spaces allowed";
        }
    }

    if (empty($_POST["email"])) {
        $emailErr = "Email is required";
    } else {
        $email = $_POST["email"];
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
        }
    }

    if (empty($_POST["phone-num"])) {
        $phoneErr = "Phone number is required";
    } else {
        $phoneNum = $_POST["phone-num"];
        if (!preg_match("/^[0-9]*$/", $phoneNum)) {
            $phoneErr = "Only numbers allowed";
        } elseif (strlen($phoneNum) != 10) {
            $phoneErr = "Phone number must be 10 digits";
        }
    }

    if (empty($_POST["password"])) {
        $passwordErr = "Password is required";
    }
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sign Up</title>
    <script src="https://cdn.jsdelivr.net/npm/@tailwindcss/browser@4"></script>
    <script src="form.js"></script>
    <style>

        body{
            display:flex;
            justify-content:center;
            align-items:center;
            height:100vh;
            flex-direction:column;
        }

        form{
            border:2px solid black;
            padding:1.5rem;
            border-radius:.5rem;
            display:flex;
            position:relative;

            flex-direction:column;
        }

        .submit-btn{
            padding:.4rem;
            border:2px solid black;
            cursor:pointer;
            transition:all .3s linear;
        }

        .submit-btn:hover{
            background:black;
            color:white;
        }

        .credentials{
            padding:.3rem;
            border:2px solid black;
        }

        #show{
            position:absolute;
            top:7.4rem;
            left:11rem;
            cursor:pointer;
        }

        .noAcc{
            font-size:.8rem;
            text-align:center;
        }


    </style>
</head>
<body>

    <h2>Sign Up</h2>
    <form name="myForm" method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    <label>Name:</label>
    <input type="text" name="name" value="<?php echo $name; ?>">
    <span style="color:red"><?php echo $nameErr; ?></span>
    <br>

    <label>Email:</label>
    <input type="text" name="email" value="<?php echo $email; ?>">
    <span style="color:red"><?php echo $emailErr; ?></span>
    <br>

    <label>Phone:</label>
    <input type="text" name="phone-num" value="<?php echo $phoneNum; ?>">
    <span style="color:red"><?php echo $phoneErr; ?></span>
    <br>

    <label>Password:</label>
    <input type="password" name="password">
    <span style="color:red"><?php echo $passwordErr; ?></span>
    <br>

    <input type="submit" value="Submit">
</form>

    
    
</body>
</html>