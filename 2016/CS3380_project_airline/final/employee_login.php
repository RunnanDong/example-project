<!DOCTYPE html>
<html>
<head>
<style>
    .login{
        border:1px solid black;
        border-collapse:collapse;
        padding: 10px;
        text-align:center;
        width: 80%;
    }
    .username{
        padding: 10px;
    }
    
   
    
    
</style>
    <!-Bootstrap Alerts>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  
  
  
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body>
      
    <form action="employee_login.php" method="post">
        <nav class="navbar navbar-inverse navbar-fixed-top">
  <div class="container-fluid">
    <div class="navbar-header">
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>                        
      </button>
      <a class="navbar-brand" href="#">Missouri Airlines</a>
    </div>
    <div>
      <div class="collapse navbar-collapse" id="myNavbar">
        <ul class="nav navbar-nav">
          <li><a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/new_mainpage.php">Home page</a></li>
          <li><a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/customer_login.php">Customer</a></li>
          <li><a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/employee_login.php">Employee</a></li>
        </ul>
      </div>
    </div>
  </div>
</nav>    
        <br><br><br>
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">Firstname:</label>
                <input class="form-control" type="text" name="firstname">
            </div>
        </div>
        <br><br><br><br>
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">Password:</label>
                <input class="form-control" type="text" name="password">
            </div>
        </div>
        <br><br><br><br>
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">Employee ID:</label>
                <input class="form-control" type="text" name="employee_id">
            </div>
        </div>
        <br><br><br><br>
            
            <label class="radio-inline username">
            <b><input type="radio" name="radio" value="0"  class="username">Administrator</b>
            </label>
            <label class="radio-inline username">
            <b><input type="radio" name="radio" value="1" class="username">Pilot</b>
            </label>
            <label class="radio-inline username">
            <b><input type="radio" name="radio" value="2" class="username">Flight attendant</b>
            </label>
            <br>
            <div class="username">
            <button class="btn btn-success" type="submit" name="submit" value="submit">Log in</button>
            <button class="btn btn-warning" type="submit" name="reset" value="reset">Reset</button>
            </div>
   
        
        
    </form>

    
<?php
    $hostname1 = 'localhost';
    $username1 = 'rdyz6';
    $password1 = 'S1tudent!';
    $database1 = 'CS3380GRP4';
    $conn=mysqli_connect($hostname1,$username1,$password1,$database1) or die("can not connect to database:".mysqli_connect_error());
    error_reporting(0);
    
        $firstname=$_POST['firstname'];
        $password=$_POST['password'];
        $employeeid=$_POST['employee_id'];
        
        if($_POST['submit']){
            if($_POST['firstname'] && $_POST['password'] && $_POST['employee_id']){
              
                 if(isset($_POST['radio'])){
                      switch($_POST['radio']){
                         case 0: $temp = "Admin";break;
                         case 1: $temp = "pilot";break;
                         case 2: $temp = "flight_attendant";break;
                }
              }
        
                $firstnameResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname'")or die("Connection error:".mysqli_connect_error());
        
                $passwordResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
        
                $idResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname' AND employee_num='$employeeid' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
                
                $checkResult=mysqli_query($conn,"SELECT *FROM $temp WHERE employee_num='$employeeid'")or die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>You did not choose any position!</div>".mysqli_connect_error()) ;
        
                $fname=mysqli_num_rows($firstnameResult);
                $pass=mysqli_num_rows($passwordResult);          
                $cid=mysqli_num_rows($idResult);
                $check=mysqli_num_rows($checkResult);
                
        }
                
                 if($fname==0){
                     die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>That name doesn't exist!</div>");
                 }
                else if($pass==0){
                    die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Incorrect password!</div>");
                }
                else if($cid==0){
                    die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Incorrect employee id!</div>");
                }
                else if($check==0){
                    die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>You are not $temp! Choose your right position</div>");
                }
               
                else{
                    
                    if(isset($_POST['radio'])){
                      switch($_POST['radio']){
                         case 0: $temp = "Admin";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/adminMain.php");
                              die("<div class='alert alert-success alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Welcome back,<i>$firstname</i>.</strong>Customer is god.</div>");
                              break;
                         case 1: $temp = "pilot";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee/profile.php");
                              die("<div class='alert alert-success alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Welcome back, pilot <i>$firstname</i>.</strong>Enjoy your flight.</div>");
                              break;
                         case 2: $temp = "flight_attendant";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee/profile.php");
                              die("<div class='alert alert-success alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Welcome back, <i>$firstname</i>.</strong>You can check your e-mail today first.</div>");
                              break;
                }
              }
            }
                
     
       
      
    }
      
    
?>
</body>
</html>