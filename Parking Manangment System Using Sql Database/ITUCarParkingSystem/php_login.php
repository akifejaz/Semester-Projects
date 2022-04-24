<?php
    
    session_start();
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

   	 $id = $_POST['ID'];
     $pass = $_POST['password'];
     $rolee = $_POST['role'];



    if ( !empty($id) && !empty($pass) && !empty($rolee) ) 
    {

        if($rolee==='Admin'){

            $admin_data = "select * from employee as s where s.CNIC = '$id' AND s.PASSWORD ='$pass' AND s.Desig_ID = 1 ";

            $result = mysqli_query($conn, $admin_data);
            if(mysqli_num_rows($result) > 0){

                header("Location: admin.php");
            }
            else {

                echo "NO Data Available With These Details";
            } 
        }
        else if($rolee === 'User') {

            $_SESSION['ID'] = $id;
            //echo "Session variables are set.";

            $user_data = "select * from new_signup as s where s.ID = '$id' AND s.PASSWORD ='$pass'  ";

            $result = mysqli_query($conn, $user_data); 
            if(mysqli_num_rows($result) > 0){
                
                header("Location: index.html");
            }
            else {

                echo "NO Data Available With These Details";
            } 
        }
        else if($rolee === 'operator'){

            $_SESSION['ID'] = $id;
            $operator_data = "select * from employee as s where s.CNIC = '$id' AND s.PASSWORD ='$pass' AND s.Desig_ID = 2 ";

            $result = mysqli_query($conn, $operator_data);
            if(mysqli_num_rows($result) > 0){

                //echo "Welcom Operator You can add comming cars here!";
                header("Location: OperatorPanel.php");
            }
            else {

                echo "NO Data Available With These Details";
            } 

        }
     

        
    }

    else {

        echo " Please Fill the Details !";
    }

}


?>