<?php

//error_reporting(0);
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "itucarparkingsystem";

// Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        
        die("Connection failed: " . $conn->connect_error);
    }
    else
    {
    

     $name = $_POST['name'] ;
   	 $email = $_POST['email'];
     $pass = $_POST['password'];

      if (!empty($name) && !empty($email) &&  !empty($pass) ) 
     {

     	$data = "INSERT INTO signup values ('?','$name','$email' ,'$pass')";

     	// sql data

            if ($conn->query($data) === TRUE) {
                echo "<br> New record created successfully! <br>";

                			mysqli_query($conn, $data);
                 			header("Location: signinlog.php");
                			die;
             }
            else {
                    echo "Error: " . $data . "<br>" . $conn->error;
                }

      }
 		
 	
 	else {

 		echo "Fill Details Completly!";
 	}
}

?>