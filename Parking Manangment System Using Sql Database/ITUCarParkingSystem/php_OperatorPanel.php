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

   	 $id = $_POST['regno'];     
     $atime = $_POST['arrivaltime'];
     $sID = $_POST['section_iD'];
     $bran = $_POST['brand'];



    if ( !empty($id) && !empty($atime) && !empty($sID) && !empty($bran) ) 
    {


        $temp = "select * from vehicle as v where v.Reg_No = '$id' ";
        $result = mysqli_query($conn, $temp);

        if(mysqli_num_rows($result) > 0){

                
            }
        else {

                //echo '<script>alert("Register Yourself Details Not found")</script>';
                echo "<script type='text/javascript'>alert('Register Yourself No Details availble for Your Reg_No');
                window.location='signinlog.php';
                </script>";

                //header("Location: signinlog.php");
        } 

    
     $tim = date("h:i:sa"); $day = date("Y-m-d");
     /*$data = "INSERT INTO parking_details values ('$opid',$id','$day','$atime','NULL' ,'$sID')";
     $result1 = mysqli_query($conn, $data);
     if(mysqli_num_rows($result) > 0){

        header("Location: OperatorPanel.php");
     }
     
      else {

                echo "NO Data Available With These Details";
        }*/

        $opid = $_SESSION['ID'];
        $data = "INSERT INTO parking_details values ('$opid','$id','CURDATE()','$tim','00:00:00' ,
        '$sID')";
        if (mysqli_query($conn, $data)) {

            echo "<script type='text/javascript'>alert('Added Done !');
                window.location='OperatorPanel.php';
                </script>";
        }
        else {
            echo "Error: " . $data . "<br>" . mysqli_error($conn);
        }
  
    }

    else {

        echo " Please Fill the Details !";
    }

}


?>