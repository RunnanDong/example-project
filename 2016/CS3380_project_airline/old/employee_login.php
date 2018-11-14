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
    <form action="employee_login.php" method="post">
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
            <td><b>Employee ID:</b></td>
            <td><input class="username" type="text" name="employee_id"></td>
        </tr> 
        <tr>    
            <td><b><input type="radio" name="radio" value="0"  class="username">Administrator</b></td>
            <td><b><input type="radio" name="radio" value="1" class="username">Pilot</b></td>
            <td><b><input type="radio" name="radio" value="2" class="username">Flight attendant</b></td>
        </tr>    
        
        <tr>
            <td><input class="username" type="submit" name="submit" value="submit"></td>
        </tr> 
        
        </table>
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
                echo"$temp<br>";
        
                $firstnameResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname'")or die("Connection error:".mysqli_connect_error());
        
                $passwordResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
        
                $idResult=mysqli_query($conn,"SELECT *FROM employee WHERE f_name = '$firstname' AND employee_num='$employeeid' AND password='$password'")or die("Connection error:".mysqli_connect_error()) ;
                
                $checkResult=mysqli_query($conn,"SELECT *FROM $temp WHERE employee_num='$employeeid'")or die("Connection error*:You did not choose any position!".mysqli_connect_error()) ;
        
                $fname=mysqli_num_rows($firstnameResult);
                $pass=mysqli_num_rows($passwordResult);          
                $cid=mysqli_num_rows($idResult);
                $check=mysqli_num_rows($checkResult);
                
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
                    die("Incorrect employee id!");
                }
                else if($check==0){
                    die("You are not $temp! Choose your right position");
                }
               
                else{
                    
                    if(isset($_POST['radio'])){
                      switch($_POST['radio']){
                         case 0: $temp = "Admin";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/adminMain.php");
                              echo "User: $firstname<br>";
                              echo "ID: $employeeid<br>";
                              echo "Position: Administor<br>";
                              die("You are now logged in as $firstname");
                              break;
                         case 1: $temp = "pilot";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee/profile.php");
                              echo "User: $firstname<br>";
                              echo "ID: $employeeid<br>";
                              echo "Position: Pilot<br>";
                              die("You are now logged in as $firstname");
                              break;
                         case 2: $temp = "flight_attendant";
                              header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee/profile.php");
                              echo "User: $firstname<br>";
                              echo "ID: $employeeid<br>";
                              echo "Position: Flight attendant<br>";
                              die("You are now logged in as $firstname");
                              break;
                }
              }
                    //echo"ABC:$temp<br>";
                   
                    
                    //if($temp = "Admin"){
                    //header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/adminMain.php");
                  //  echo "User: $firstname<br>";
                   // echo "ID: $employeeid<br>";
                   // echo "Position: Administor<br>";
                   // die("You are now logged in as $firstname");
                  // }
                   // else if($temp = "pilot"){
                    //header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee.php");
                   // echo "User: $firstname<br>";
                   // echo "ID: $employeeid<br>";
                   // echo "Position: Pilot<br>";
                   // die("You are now logged in as $firstname");
                   // }
                    //else if($temp = "flight_attendant"){
                    //header("refresh:3;url=http://cs3380.rnet.missouri.edu/group/CS3380GRP4/www/employee.php");
                   // echo "User: $firstname<br>";
                    //echo "ID: $employeeid<br>";
                   // echo "Position: Flight attendant<br>";
                   // die("You are now logged in as $firstname");
                  //  }
                    
                }
                
     
       
      
    }
      
    
?>
</body>
</html>