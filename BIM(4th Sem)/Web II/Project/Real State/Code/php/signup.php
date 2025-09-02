 <?php
    $server="localhost";
    $username="root";
    $password="";
    $dbName="user";

    // Establish connection
    $conn=new mysqli($server,$username,$password,$dbName);
    if($conn->error){
        echo "Connection failed";
    }
    echo "Connection succesful";

    // $sql="CREATE TABLE USER(
    //         first_name VARCHAR(30) NOT NULL,
    //         last_name VARCHAR(30) NOT NULL,
    //         email VARCHAR(40) NOT NULL,
    //         password VARCHAR(40) NOT NULL
    //     );";
    // if($conn->query($sql)){
    //     echo "<br>Table created successfully";
    // }
    // else{
    //     echo "Table creation failed";
    // }

    // Insert credentials into database
    $first_name=$_POST['fname'];
    $last_name=$_POST['lname'];
    $password=$_POST['password'];
    $email=$_POST['email'];

    $sql="INSERT INTO USER(first_name,last_name,email,password)
          VALUES('$first_name','$last_name','$email','$password');";

    if($conn->query($sql)){
        echo "<br>Data inserted successfully";
    }
    else{
        echo "Data insertion failed";
    }

    $sql="SELECT * FROM USER;";
    echo $conn->query($sql);
    
    // Close connection
    $conn->close();
?>
