<?php
  session_start();
  //error_reporting(0);
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "itucarparkingsystem";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Details Section</title>
  <link href="https://unpkg.com/tailwindcss@1.0.6/dist/tailwind.min.css" rel="stylesheet">
</head>
<body>
<section class="text-whilte-600 body-font" style="background-color: ;">
  <div class="container px-5 py-24 mx-auto">
    <div class="flex flex-col text-center w-full mb-20">
      <h1 class="sm:text-4xl text-3xl font-medium title-font mb-2 text-gray-900">Your Details Section</h1>
      <p class="lg:w-2/3 mx-auto leading-relaxed text-base">Banh mi cornhole echo park skateboard authentic crucifix neutra tilde lyft biodiesel artisan direct trade mumblecore 3 wolf moon twee</p>
    </div>
    <div class="lg:w-2/3 w-full mx-auto overflow-auto">
      <table class="table-auto w-full text-left whitespace-no-wrap">
        <thead>
          <tr>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100 rounded-tl rounded-bl">Operator_CNIC</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">V_reg_no</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">Pdate</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">Arrival_Time</th>
            <th class="px-4 py-3 w-10 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100 rounded-tr rounded-br">Departure_Time</th>
            <th class="px-4 py-3 w-10 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100 rounded-tr rounded-br">PS_Sec_ID</th>
          </tr>
        </thead>

        <!-- Data Entries -->

        <tbody>

        <?php
              $con = mysqli_connect("localhost","root","","itucarparkingsystem");
              if (mysqli_connect_errno()){
                      echo "Failed to connect to MySQL: " . mysqli_connect_error();
                      die();
              }
              
              $regNo = $_SESSION['ID'];

              $user_data1 = "SELECT * FROM `parking_details` as pd   ";
              $result1 = mysqli_query($conn, $user_data1);

              while($row = mysqli_fetch_assoc($result1)){
              
              ?>
                       <tr>
                                <td class="px-4 py-3"><?php echo $row['Operator_CNIC']?></td>
                                <td class="px-4 py-3"><?php echo $row['V_reg_no']?>    </td>
                                <td class="px-4 py-3"><?php echo $row['Pdate']?>   </td>
                                <td class="px-4 py-3"><?php echo $row['Arrival_Time']?> </td>
                                <td class="px-4 py-3"><?php echo $row['Departure_Time']?> </td>
                                <td class="px-4 py-3"><?php echo $row['PS_Sec_ID']?>    </td>
                        </tr>

                <?php

                    }
                

             // } 
              
          ?>
                </tbody>

        <!-- Data Entries -->

      </table>
    </div>

    <div class="flex pl-4 mt-4 lg:w-2/3 w-full mx-auto" onclick="location.href = 'admin.php';">
      <button class="flex ml-auto text-white bg-indigo-500 border-0 py-2 px-6 focus:outline-none hover:bg-indigo-600 rounded">Back To Main Page</button>
    </div>
  </div>
</section>



</body>
</html>

