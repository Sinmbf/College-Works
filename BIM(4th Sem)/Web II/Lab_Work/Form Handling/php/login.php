<?php
    // Start session if needed
    session_start();

    // Get form input
    $username=$_POST['username'];
    $password=$_POST['password'];

    // Check login
    if($username=='admin' && $password=='12345'){
        // optional store session data
        $_SESSION['username']=$username;
        // Redirect to welcome page
        header("Location: welcome.php");
        exit();
    }
    else{
        // Redirect back to login page
        header("Location: failedLogin.php");
    }