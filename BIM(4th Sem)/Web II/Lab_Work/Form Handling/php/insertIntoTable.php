<?php
    $servername="localhost";
    $username="root";
    $password="";
    $database="Sinmbf";
    $user=$_POST['username'];
    $pass=$_POST['password'];

    $conn=mysqli_connect($servername,$username,$password,$database);
    if(!$conn){
        die("Connection failed<br>".mysqli_connect_error());
    }
    echo "Connected successfully";

    // Create table
    $sql="INSERT INTO user1(username,password) VALUES($user,$pass);";
    
    // Execute query
    if(mysqli_query($conn,$sql)===TRUE){
        echo "<br>Data inserted successfully";
    }
    else{
        echo "Error inserting table".mysqli_error($conn);
    }
?>