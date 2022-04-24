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
    
   // echo "<br>Sign up Connected successfully! <br>";
     $id = $_POST['id'] ;
     $name = $_POST['name'] ;
   	 $email = $_POST['email'];
     $pass = $_POST['password'];

      if (!empty($name) && !empty($email) &&  !empty($pass) && !empty($id)) 
     {

        $data = "INSERT INTO new_signup values ('$id','$name','$email' ,'$pass')";
        if (mysqli_query($conn, $data)) {}
        else {
            echo "Error: " . $data . "<br>" . mysqli_error($conn);
        }

        //----------------------
        $sql = "INSERT INTO vehicle (Reg_No, Owner_Name, V_Type,Brand)
        VALUES ('$id', '$name', 'Car','NULL')";

        if (mysqli_query($conn, $sql)) {
            
            echo "New record created ";
            header("Location: signinlog.php");

        } else {
            echo "Error: " . $sql . "<br>" . mysqli_error($conn);
        }
        //------------------------- 
/*
        $today = date("F j, Y, g:i a");
        $da = date("Y/m/d"); $tim = date("h:i:sa");
        $sql1 = "INSERT INTO parking_details (Operator_CNIC, V_reg_no, Pdate,Arrival_Time,Departure_Time,PS_Sec_ID) VALUES ('55', '$id', '$da','$tim','NULL','AA-167')";

        if (mysqli_query($conn, $sql1)) {
            echo "New record created successfully";
        } else {
            echo "Error: " . $sql1 . "<br>" . mysqli_error($conn);
        }
        //-------------------------

*/

      }
 		
 	
 	else {

 		echo "Fill Details Completly!";
 	}
}

?>