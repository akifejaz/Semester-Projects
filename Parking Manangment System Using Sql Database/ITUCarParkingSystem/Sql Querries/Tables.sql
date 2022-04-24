CREATE DATABASE PMS_Aatir_Akif;   --Parking Management System

USE PMS_Aatir_Akif

CREATE TABLE Designation(
	ID int,
	Roll varchar(20),
	Job_Description varchar(50),

	Primary Key(ID)
);

CREATE TABLE Employee(
	CNIC varchar(15),
	[Name] varchar(30),
	Desig_ID int,         --FK
	[Address] varchar(50),
	ContactNo numeric(11),
	Super_CNIC varchar(15), --FK

	Primary Key (CNIC),
	Foreign Key (Super_CNIC) References Employee(CNIC),
	Foreign Key (Desig_ID) References Designation(ID)
);

CREATE TABLE Vehicle_Type(
	ID int,
	V_Type_Name varchar(10),

	Primary Key (ID)
);

CREATE TABLE Vehicle(
	Reg_No varchar(9), -- ABC1234YY
	Owner_Name varchar(30),
	V_Type_ID int,    --FK
	Brand varchar(20),

	Primary Key (Reg_No),
	Foreign Key (V_Type_ID) References Vehicle_Type(ID)
);

CREATE TABLE Parking_Area(
	ID int,
	[Location] varchar(20),
	no_of_Floors int,
	Admin_CNIC varchar(15), --FK

	Primary Key (ID),
	Foreign Key (Admin_CNIC) References Employee(CNIC)
);

CREATE TABLE PA_Imp_Level(
	ID int,
	PA_ID int,  --FK
	VT_ID int,  --FK
	Imp_level int, 

	Foreign Key (PA_ID) References Parking_Area(ID),
	Foreign Key (VT_ID) References Vehicle_Type(ID),
	Primary Key (ID)
);

CREATE TABLE PA_Specs(
	ID int,
	Capacity int,
	Price int,

	Foreign Key (ID) References PA_Imp_Level(ID),
	Primary Key (ID)
);

CREATE TABLE Parking_Spot(
	Section_ID varchar(6),  -- AA-111
	Spec_ID int,    --FK
	Floor_No int,

	Primary Key (Section_ID),
	Foreign Key (Spec_ID) References PA_Imp_Level(ID),
);

CREATE TABLE Parking_Details(
	Operator_CNIC varchar(15),  --FK PK
	V_reg_no varchar(9),  --FK PK
	[Date] date,
	Arrival_Time time,
	Departure_Time time,
	PS_Sec_ID varchar(6), --FK

	Primary Key (Operator_CNIC, V_reg_no),
	Foreign Key (Operator_CNIC) References Employee(CNIC),
	Foreign Key (V_reg_no) References Vehicle(Reg_No),
	Foreign Key (PS_Sec_ID) References Parking_Spot(Section_ID),
);


SELECT * FROM Designation 
go
SELECT * FROM Employee 
go
SELECT * FROM Vehicle_Type 
go
SELECT * FROM Vehicle 
go
SELECT * FROM Parking_Area 
go
SELECT * FROM PA_Imp_Level 
go
SELECT * FROM PA_Specs 
go
SELECT * FROM Parking_Spot 
go
SELECT * FROM Parking_Details

