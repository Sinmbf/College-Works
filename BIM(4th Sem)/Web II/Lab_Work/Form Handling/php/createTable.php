<?php
    $servername="localhost";
    $username="root";
    $password="";
    $database="Sinmbf";

    $conn=mysqli_connect($servername,$username,$password,$database);
    if(!$conn){
        die("Connection failed<br>".mysqli_connect_error());
    }
    echo "Connected successfully";

    // Create table
    $sql="CREATE TABLE user1(
        username VARCHAR(30) NOT NULL,
        password VARCHAR(30) NOT NULL
        );";
    
    // Execute query
    if(mysqli_query($conn,$sql)===TRUE){
        echo "<br>Table 'user1' created successfully";
    }
    else{
        echo "Error creating table".mysqli_error($conn);
    }
?>