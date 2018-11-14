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
</head>
<body>
    <div>
    <h1 class="login">Login</h1>
    </div><br>    
    <form action="customer_login.php" method="post">
        <table>
        <tr>
            <td><b>Firstname:</b></td>
            <td><input class="username" type="text" name="firstname"></td>
        </tr>
        <tr>
            <td><b>Password:</b></td>
            <td><input class="username" type="text" name="password"></td>
        </tr>
        <tr>
            <td><b>Customer ID:</b></td>
            <td><input class="username" type="text" name="customer_id"></td>
        </tr>        
        <tr>
            <td><input class="username" type="submit" name="submit" value="submit"></td>
        </tr> 
        </table>
    </form>
    <h2>Create your account!<a href="http://cs3380.rnet.missouri.edu/~rdyz6/final/customer_register.php">Register</a></h2>
    
    
    
    
    
    
    

    
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
                echo "_User: $fname<br>";
                echo "_Password: $pass<br>";
                echo "_ID: $cid<br>";
                
                 if($fname==0){
                     die("That name doesn't exist!");
                 }
                else if($pass==0){
                    die("Incorrect password!");
                }
                else if($cid==0){
                    die("Incorrect customer_id!");
                }
                else{
                    header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/customersearch.php");
                    echo "User: $firstname<br>";
                    echo "ID: $customerid<br>";
                    die("You are now logged in as $firstname");
                    
                }
                
     
       
      
    }
      
    
?>
</body>
</html>
