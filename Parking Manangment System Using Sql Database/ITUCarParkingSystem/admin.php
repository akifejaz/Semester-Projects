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
<!-- Designined by CodingLab | www.youtube.com/codinglabyt -->
<html lang="en" dir="ltr">
  <head>
    <meta charset="UTF-8">
    <title> Admin Portal </title>
    <link rel="stylesheet" href="style.css">
  <link href="https://unpkg.com/tailwindcss@1.0.6/dist/tailwind.min.css" rel="stylesheet">
    <!-- Boxiocns CDN Link -->
    <link href='https://unpkg.com/boxicons@2.0.7/css/boxicons.min.css' rel='stylesheet'>
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
   </head>

<body>
  
  <div class="sidebar close">
    <div class="logo-details">
      <i class='bx bx-taxi'></i>
      <span class="logo_name">Admin Portal</span>
    </div>
    <ul class="nav-links">
      <li>
        <a href="#">
          <i class='bx bx-grid-alt' ></i>
          <span class="link_name">Dashboard</span>
        </a>
      
    <div class="profile-details">
      <div class="profile-content">
        <img src="assets/img/profile.png" alt="profileImg">
      </div>
      <div class="name-job">
        <div class="profile_name">LogOut</div>
        
      </div>
      <a href="signinlog.php">
      <i class='bx bx-log-out' ></i>
    </a>
    </div>
  </li>
</ul>

  </div>
  <section class="home-section">
    <div class="home-content">


      <i class='bx bx-menu' ></i>
      <span class="text">Dashboard</span>
      <div class="wrapper">
        <div class="search_box">
            <input type="text" placeholder="what are you looking for?">
            <i class="fas fa-search"></i>
        </div>
        
      </div>

      </div>
<section class="text-gray-600 body-font" style="background-color: ;">
  <div class="container px-5 py-24 ml-20 flex items-center">
   
    <a href="allparkingdetails.php">
    <button class="bg-gray-100 inline-flex py-10 mx-10 px-8 rounded-lg items-center hover:bg-gray-200 focus:outline-none">
        
          <span class="flex items-start flex-col leading-none">
          <span class="title-font font-medium">All Parking Details</span>

        </span>
      </button> 

      <a href="allusersdetails.php">
      <button class="bg-gray-100 inline-flex py-10 mx-10 px-8  rounded-lg items-center hover:bg-gray-200 focus:outline-none">
        
        
        <span class="flex items-start flex-col leading-none">
        <span class="title-font font-medium">All Users </span>

        </span>
      </button></a>

      <a href="allvehiclesdetails.php">
      <button class="bg-gray-100 inline-flex py-10 mx-10 px-8  rounded-lg items-center hover:bg-gray-200 focus:outline-none">
        
          <span class="flex items-start flex-col leading-none">
          <span class="title-font font-medium">All Vehicles Details</span>

        </span>
      
      </button></a>

      <!-- <input  name= placeholder="Enter ID To Delete User"> -->
      
    
  </div>
</section>
    
    <form action="deleteuser.php" method="post">
      
    <!-- <a href="deleteuser.php"> -->
    <div class="inline-flex ml-20 py-2 pl-20">
    <!-- <button class="bg-gray-100 inline-flex py-2 px-20" style="border-radius: 15px;"> -->
    

    <input class="bg-gray-100 inline-flex py-2 m-2 px-20" type="ID" name="ID" placeholder="Enter ID To Delete User">
    
    <!-- </button> -->

    </form>


</div>
<!-- </a> -->
  </section>
  

  

  <script src="script.js"></script>
  

</body>
</html>
