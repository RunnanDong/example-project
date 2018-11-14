<DOCCTYPE html>
<html>
<head>
    <titlte>add Flight Attendant</titlte>
    <style>
        table,th,td { border: 1px solid black;}
		tab1 { padding-left: 1em; }
    </style>
    <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
	<a href="./adminMain.php">Back To Menu</a> <br><br>
	Add a New Pilot <br><br>
</head>
<body>
	
	<form method="POST" action="addFA.php" onSubmit = "return confirm('Confirm New Flight Attendant')" class="form-horizontal">
        <div class="col-sm-10"> First Name:<br>
            <div><input class="form-control" type = "text" name="fname" value=""><br><br></div>
        </div>
        <div>Last Name:<br>	
			<div><input type = "text" name="lname" value=""><br><br></div>
        </div>
		<div>SSN:<br>	
            <div><input type = "text" name="ssn" value=""><br><br></div>
        </div>
		<div>Date of Birth: <br>
			<div><input type="date" name="bday"><br><br></div>
        </div>
        <div>Phone Number:<br>	
            <div><input type = "text" name="phone" value=""><br><br></div>
        </div>
        <div>
		Rank:<tab1><select name = "rank">
			<option value='Trainee'>Trainee</option>
			<option value='Junior'>Junior</option>
			<option value='Senior'>Senior</option>
		</select><br><br>
            </tab1>
        </div>
		<div> Flight Number:<br>	
					<input type="number" name="num"min="0" max="10000" step="1" value=""><br><br>
        </div>
        <input type="submit" name="submitfa" value="Submit">
   </form>

    </body>
</html>

<?php


if(isset($_POST['submitfa']))
{
	$serverName = "localhost";
    $username =   "nokz8f";
    $password = "RAdsworth1012";
    $database =   "CS3380GRP4";
       
    $conn = mysqli_connect($serverName, $username, $password, $database); 
    
    if(mysqli_connect_error()){
        echo "Connection Failed: " . mysqli_connect_error();
    }
		
		$query = "INSERT INTO employee VALUES(DEFAULT,'password',?,?,?,?,'fa',?)";
		$query2 = "INSERT INTO flight_attendant VALUES(?,?,?)";
		
		$stmt1 = mysqli_prepare($conn,$query);
		mysqli_stmt_bind_param($stmt1,"sssss", $_POST['fname'], $_POST['lname'], $_POST['ssn'], $_POST['bday'], $_POST['phone']);
		mysqli_stmt_execute($stmt1);
		mysqli_stmt_close($stmt1);
		
		$result = mysqli_query($conn,"SELECT employee_num FROM employee WHERE ssn = '".$_POST['ssn']."'");
		$row = mysqli_fetch_row($result);
		foreach($row as $value){ }
			
		$stmt2 = mysqli_prepare($conn,$query2);
		mysqli_stmt_bind_param($stmt2,"isi",$value,$_POST['rank'],$_POST['num']);
		mysqli_stmt_execute($stmt2);
		mysqli_stmt_close($stmt2);		
	
	mysqli_close($conn);
	
}
?>