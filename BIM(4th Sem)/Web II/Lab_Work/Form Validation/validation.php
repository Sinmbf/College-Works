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
