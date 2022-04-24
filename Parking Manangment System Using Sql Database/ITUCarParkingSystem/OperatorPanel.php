<<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Operator Pannel</title>
	<link href="OperatorPanel.css" rel="stylesheet">
</head>
<body>

<div class="login-box">
  <h2>Vehicle Parking Details</h2>
  <form action="php_OperatorPanel.php" method="post" >

    <div class="user-box">
      <input type="text" name="regno" required="">
      <label>Vehicle Registration Number </label>
    </div>

    <div class="user-box">
      <input type="time" name="arrivaltime" id="appt" name="appt" required="">
      <label>Arrival Time </label>
    </div>
    <div class="user-box">
      <input type="section_id" name="section_iD" required="">
      <label>Parking Section ID (AA-167,BB-111,BB-221)</label>
      <!-- <select name="area" id="areas">
    	<option value="AA-167">AA-167</option>
    	<option value="BB-111">BB-111</option>
    	<option value="BB-221">BB-221</option>
    	<option value="BB-331">BB-331</option>
    	<option value="AB-182">AB-182</option> -->
    </div>
    <div class="user-box">
      <input type="brand" name="brand" required="">
      <label>Brand/Model Of Car</label>
    </div>

    <button>Submit</button>
  </form>

</div>
</body>
</html>

