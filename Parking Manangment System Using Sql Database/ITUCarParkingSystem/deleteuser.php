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

$data = $_POST['ID'];
// sql to delete a record
$sql = "DELETE FROM new_signup WHERE ID = $data ";

if ($conn->query($sql) === TRUE) {

  echo "Record deleted successfully";
} else {
  echo "Error deleting record: " . $conn->error;
}

}

$conn->close();
?>