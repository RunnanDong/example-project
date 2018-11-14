DROP TABLE if exist Employee;
DROP TABLE if exist Admin;
DROP TABLE if exist Pilot;
DROP TABLE if exist Flight_Attendant;
DROP TABLE if exist Plane;
DROP TABLE if exist Flight;
DROP TABLE if exist Reservation;
DROP TABLE if exist Customer;
DROP TABLE if exist Certified;


create table Employee(
	employee_num INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
	password varchar(15) NOT NULL
	f_name varchar(15),
	l_name varchar(20),
	SSN int,
	DOB DATE,
    TYPE vachar(2) NOT NULL, /* pi,ad,or fa */
	phone_num varchar(13)
);

create table Customer(
    customer_id INT PRIMARY KEY NOT NULL,
    password varchar(15) NOT NULL,
    bag_num INT(3),
    DOB DATE,
    ticket_num SMALLINT;
    cc_num int,
    SSN int(9),
    f_name varchar(15),
    l_name varchar(20),
    app_status varchar(30)
);

create table Flight(
    flight_id int PRIMARY KEY NOT NULL,
	dept_city varchar(25),
	dept_state varchar(2),
	dept_time TIME,
	est_landing_time TIME,
	flight_codes varchar(20)
);

create table Reservation(
	confirmation_num int PRIMARY KEY NOT NULL,
	seat_num int
    customer_id INT NOT NULL,
    flight_id INT NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id)
);

create table Flight_Attendant(
    employee_num INT PRIMARY KEY NOT NULL,
	fa_rank varchar(15) NOT NULL,
	current_city varchar(25),
	current_state varchar(2),
    flight_id INT NOT NULL,
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id)
    FOREIGN KEY (employee_num) REFERENCES Employee(employee_num)
);

create table Pilot(
	employee_num INT PRIMARY KEY NOT NULL,
    p_rank varchar(15) NOT NULL,
	flight_hours int,
	flight_num INT,
	current_city varchar(25),
	current_state varchar(2),
    flight_id INT NOT NULL,
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id),
    FOREIGN KEY (employee_num) REFERENCES Employee(employee_num)
);

create table Plane(
	plane_id PRIMARY KEY NOT NULL,
    model_num varchar(20) NOT NULL,
	capacity_min INT,
	capacity_max INT,
	plane_status varchar(10),
	p_req INT,
	fa_req INT,
	flight_num INT,
	flight_hours INT,
	location_city varchar(25),
	location_state varchar(2)
    flight_id INT,
    FOREIGN KEY (flight_id) REFERENCES Flight(flight_id)
);

create table Admins(
    employee_num INT PRIMARY KEY NOT NULL,
	office varchar(20),
	office_num INT
    FOREIGN KEY (employee_num) REFERENCES Employee(employee_num)
);

create table Certified(
    employee_num INT NOT NULL,
	model_num varchar(20) NOT NULL,
    FOREIGN KEY (employee_num) REFERENCES Pilot(employee_num),
    FOREIGN KEY (model_num) REFERENCES Plane(model_num)
);


