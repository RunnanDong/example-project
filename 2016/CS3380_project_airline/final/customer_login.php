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
    
    .inputstyle{
      text-align:center;
        padding: 2px;
        
    }
    
</style>
  <!-Bootstrap Alerts>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  
 
    
   
</head>
<body >  
    <form action="customer_login.php" method="post">
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
            <label for="ex2">Customer ID:</label>
            <input class="form-control" type="text" name="customer_id"></div>
        </div>
        <br><br><br><br>
        <div class="username">
            <button class="btn btn-success" type="submit" name="submit" value="submit">Log in</button>
            <button class="btn btn-warning" type="submit" name="reset" value="reset">Reset</button>
        </div>
        
            
        
    </form>
    
    <div>
    <h2 class="username">Don't have account?Click here.<a href="http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/customer_register.php">Register</a></h2>
    </div>
    
    
    
    
    
    
    

    
<?php
    $hostname1 = 'localhost';
    $username1 = 'rdyz6';
    $password1 = 'S1tudent!';
    $database1 = 'CS3380GRP4';
    $conn=mysqli_connect($hostname1,$username1,$password1,$database1) or die("can not connect to database:".mysqli_connect_error());
    error_reporting(0);
    
        $firstname=$_POST['firstname'];
        $password=$_POST['password'];
        $customerid=$_POST['customer_id'];
        if($_POST['submit']){
            if($_POST['firstname'] && $_POST['password'] && $_POST['customer_id']){
                
                
                
        
                $firstnameResult=mysqli_query($conn,"SELECT *FROM customer WHERE f_name = '$firstname'")or die("Connection error:".mysqli_connect_error());
        
                $passwordResult=mysqli_query($conn,"SELECT *FROM customer WHERE f_name = '$firstname' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
        
                $idResult=mysqli_query($conn,"SELECT *FROM customer WHERE f_name = '$firstname' AND customer_id='$customerid' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
        
                $fname=mysqli_num_rows($firstnameResult);
                $pass=mysqli_num_rows($passwordResult);          
                $cid=mysqli_num_rows($idResult);
                
                
        }
               // echo "_User: $fname<br>";
              //  echo "_Password: $pass<br>";
              //  echo "_ID: $cid<br>";
                
                 if($fname==0){
                     die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>That name doesn't exist!</div>");
                 }
                if($pass==0){
                    die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Incorrect password!</div>");
                }
                if($cid==0){
                    die("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Incorrect customer_id!</div>");
                }
                else{
                    header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/customersearch.php");
                    //echo "User: $firstname<br>";
                    //echo "ID: $customerid<br>";
                    die("<div class='alert alert-success alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Welcome, $firstname.</strong>Now you are log in. Ddicated to your service.</div>");
                    
                }
                
     
       
      
    }
      
    
?>
</body>
</html>
