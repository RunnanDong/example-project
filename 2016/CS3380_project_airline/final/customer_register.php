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
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
    
</head>
<body>

    <form action="customer_register.php" method="post">
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
                <label for="ex2">Lastname:</label>
                <input class="form-control" type="text" name="lastname">
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
                <input class="form-control" type="text" name="customer_id">
            </div>
        </div>
        <br><br><br><br>
        
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">Date of birth:</label>
                <input class="form-control" type="date" name="dob">
            </div>
        </div>
        <br><br><br><br>
        
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">SSN:</label>
                <input class="form-control" type="text" name="ssn">
            </div>
        </div>
        <br><br><br><br>
        <div class="form-group">
            <div class="col-xs-3">
                <label for="ex2">Bag number:</label>
                <input class="form-control" type="text" name="bag_num">
            </div>
        </div>
        <br><br><br><br>
        <input class="username" type="submit" name="register" value="register">
             
       
    </form>
   
    
<?php
    $hostname1 = 'localhost';
    $username1 = 'rdyz6';
    $password1 = 'S1tudent!';
    $database1 = 'CS3380GRP4';
    $conn=mysqli_connect($hostname1,$username1,$password1,$database1) or die("can not connect to database:".mysqli_connect_error());
    error_reporting(0);
    if($_POST['register']){
        if($_POST['password']&&$_POST['customer_id']){
        
        $firstname=$_POST['firstname'];
        $lastname=$_POST['lastname'];
        $password=$_POST['password'];
        $dob=$_POST['dob'];
        $cid=$_POST['customer_id'];
        $ssn=$_POST['ssn'];
        $bnum=$_POST['bag_num'];
        
        $sql1="SELECT *FROM customer WHERE customer_id = '$cid'";
        $result=mysqli_query($conn,$sql1)or die("Connection error!:".mysqli_connect_error());
        $user=mysqli_num_rows($result);     
           if($user!=0){
            
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>That customer ID already exist!Try this <i>$cid".rand(1,50)."</i> instead!</div>");
        }
           if(!ctype_alnum($firstname)){
          
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Firstname contain special characters!</div>");
        }
           if(!ctype_alnum($lastname)){
          
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Lastname contain special characters!</div>");
        }
        
           if(strlen($firstname)>15){
          
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Uaername can not contain more than 20 characters!</div>");
        }
           if(strlen($lastname)>20){
        
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Lastname can not contain more than 20 characters!</div>");
            
        }
           if(strlen($password)>15 || strlen($password)==0){
            
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Your password is invalid!</div>");
           
        }
           if(strlen((string)$cid)>11 || strlen((string)$cid)<1){

            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Your customer id is invalid!!</div>");
            
        }
           if (!ctype_digit($cid)) {
             echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Your ID should be digit!</div>");
            
        }
           if(!is_numeric($bnum)||$bnum>3){
            echo("<div class='alert alert-warning alert-dismissable fade in'><a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a><strong>Warning!</strong>Your bag number is invalid! Please enter number again!(or you should pay money for overweight baggage.)</div>");
            
        }

        else{
          $sql="INSERT INTO customer(customer_id,password,bag_num,dob,ssn,f_name,l_name) VALUES(?,?,?,?,?,?,?)";
          if($stmt = mysqli_prepare($conn, $sql)){
           mysqli_stmt_bind_param($stmt, "isissss",$_POST['customer_id'],$_POST['password'],$_POST['bag_num'],$_POST['dob'],$_POST['ssn'],$_POST['firstname'],$_POST['lastname']) or die ("Connection error:" . mysqli_connect_error());
            if(mysqli_stmt_execute($stmt)){
            header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/customer_login.php");
            echo "<div class='alert alert-success alert-dismissable fade in'>";
            echo "<a href='#' class='close' data-dismiss='alert' aria-label='close'>&times;</a>";
            echo "<strong>User successfully inserted</strong>";
            echo"Hello <i>$firstname</i>, Your account are now created, and your password is <i>$password</i>. Your customer ID is <i>$cid</i>.<br><a href='http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/login&register/customer_login.php'>&larr;BACK!</a><br>";
            echo"</div>";
        }
            else{
                echo ":(<br>";
            }
    } 
}


    }
}
?>
</body>
</html>