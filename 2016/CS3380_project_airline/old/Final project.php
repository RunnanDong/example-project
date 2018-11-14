<?php
//$customerid = $_POST['customer_id'];
$customerid = 1;
?>
<!DOCTYPE html5>
   <html>
   <head>
           <!-- Latest compiled and minified CSS -->
           <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
   
           <!-- Optional theme -->
           <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
   
          <!-- Latest compiled and minified JavaScript -->
          <!--<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script> -->
  </head>
  
  <body class="container">
          <a href="http://cs3380.rnet.missouri.edu/~nasz8f/placeholder/placeholder.php">Back</a>
          <hr>
  
          <form action="" method="POST" class="col-md-4 col-md-offset-5" autocomplete="on">
                  Search:
                  <input type="text" name="search"></input>
                  <br><br>
                  <input type="radio" name="radios" value="t1.city" checked="check">Departure City</input>
                  <input type="radio" name="radios" value="t2.city">Destination City</input>
                  <input type="radio" name="radios" value="dept_date">Date of Departure</input>
		  <input type="radio" name="radios" value="price">Price</input>
                  <br><br>
		  Sort by: <select name="sortby">
		  <option value="t1.city">Departure City</option>
		  <option value="t2.city">Destination City</option>
		  <option value="dept_date">Date of Departure</option>
		  <option value="price">Price</option>
		  </select><br></br>
                  <input class="btn btn-primary" type="submit" name="submit" value="Display Flights">
  
          </form>
  
          <hr>
  <?php
  if(isset($_POST['submit'])){
  $search = $_POST['search'];
  $field = $_POST['radios'];
  $search = $search."%";
  $sort =  $_POST['sortby'];
          $link = mysqli_connect('localhost', 'nasz8f', 'La3442nc', 'CS3380GRP4') or die (mysqli_connect_error());
          //$sql = "SELECT * FROM classes WHERE $field LIKE ?";
	  $sql = "SELECT flight_id, t1.city as 'Depart_City' ,t1.state as 'Depart_State', t2.city as 'Destination_City', t2.state as 'Destination_State' FROM flight t JOIN location t1 ON t1.loc_id = t.depart_loc JOIN location t2 ON t2.loc_id = t.dest_loc WHERE $field LIKE ? ORDER BY $sort";
	    //$sql = "SELECT * FROM Flight";
          global $link;
          $stmt = mysqli_prepare($link,$sql) or die (mysqli_error($link));
          mysqli_stmt_bind_param($stmt,"s", $search);
          mysqli_stmt_execute($stmt);
          $result = mysqli_stmt_get_result($stmt);
                echo "<table class'table table-hover'><thead>";
                while($fieldinfo = mysqli_fetch_field($result)){
                        echo "<th>".$fieldinfo->name."</th>";
                }
                while($row = mysqli_fetch_array($result, MYSQLI_NUM)){
                        echo"<tr>";
                        foreach($row as $r){
                                echo"<td>$r</td>";
                        }
                          ?>
                                  <td>
                                  <form method="POST" action="join.php" onSubmit="return confirm('are you sure you want to join?')">
				  <?php
				  echo "<input type='hidden' name='flightid' value='$row[0]'></input>";
				  echo "<input type='hidden' name='departcity' value='$row[1]'></input>";
				  echo "<input type='hidden' name='departstate' value='$row[2]'></input>";
				  echo "<input type='hidden' name='destinationcity' value='$row[3]'></input>";
				  echo "<input type='hidden' name='destinationstate' value='$row[4]'></input>";
				  echo "<input type='hidden' name='customerid' value='$customerid'</input>";?>
                                  <input type='submit' name='join' value='Join'></input>
                                  </form>
                                  </td></tr>
                          <?php
	
                        }
  }
  
  
  ?>
  </html>
