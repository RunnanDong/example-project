<?php
$flightid = $_POST['flightid'];
//$deptdate = $_POST['departcity'];
//$depttime = $_POST['depttime'];
//$destcity = $_POST['destcity'];
$customerid = $_POST['customerid'];
?>
<!DOCTYPE html5>
<html>
<head>
</head>
<body>
<center>
<h1>SUCCESS</h1>
<h2>You have succesfully joined a flight!</h2>
</center>
</body>
<?php
$link = mysqli_connect('localhost', 'nasz8f', 'La3442nc', 'CS3380GRP4') or die (mysqli_connect_error());
$sql = "SELECT plane_id FROM flight WHERE flight_id=$flightid";
global $link;
$result = mysqli_query($link, $sql) or die("Query Error: " . mysqli_error($link));
$row = mysqli_fetch_array($result, MYSQLI_NUM);
$planeid = $row[0];

$moresql = "SELECT open_seats FROM plane WHERE plane_id = '$planeid'";
$moreresult = mysqli_query($link, $moresql) or die("Query Error: " . mysqli_error($link));
$row = mysqli_fetch_array($moreresult, MYSQLI_NUM);
//$seatsavailable = $row[0];
$seatsavailable = 1;

$seatnum = 1;
$finalsql = "INSERT INTO reservation VALUES(DEFAULT, $seatsavailable, $customerid, $flightid)";
mysqli_query($link, $finalsql) or die("Query Error: " . mysqli_error($link));
?>
</html>
