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
  <title>All Users Details Section</title>
  <link href="https://unpkg.com/tailwindcss@1.0.6/dist/tailwind.min.css" rel="stylesheet">
</head>
<body>
<section class="text-whilte-600 body-font" style="background-color: ;">
  <div class="container px-5 py-24 mx-auto">
    <div class="flex flex-col text-center w-full mb-20">
      <h1 class="sm:text-4xl text-3xl font-medium title-font mb-2 text-gray-900">All Vehicles Detail Section</h1>
     
    </div>
    <div class="lg:w-3/4 w-full mx-auto overflow-auto">
      <table class="table-auto w-full text-left whitespace-no-wrap">
        <thead>
          <tr>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100 rounded-tl rounded-bl">Reg_No</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">Owner_Name</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">Vehicle Type</th>
            <th class="px-4 py-3 title-font tracking-wider font-medium text-gray-900 text-sm bg-gray-100">Brand</th>
            
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

              $user_data1 = "SELECT * FROM `vehicle` as pd  ";
              $result1 = mysqli_query($conn, $user_data1);

              while($row = mysqli_fetch_assoc($result1)){
              
              ?>
                       <tr>
                                <td class="px-3 py-3" style="border: 1px solid black;">
                                  <?php echo $row['Reg_No']?></td>
                                <td class="px-3 py-3" style="border: 1px solid black;">
                                  <?php echo $row['Owner_Name']?>    </td>
                                <td class="px-3 py-3" style="border: 1px solid black;">
                                  <?php echo $row['V_Type']?>   </td>
                                <td class="px-3 py-3" style="border: 1px solid black;">
                                  <?php echo $row['Brand']?> </td>
                                
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

