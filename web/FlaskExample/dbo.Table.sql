CREATE TABLE [dbo].[Employee]
(
	[EmployeeID] INT NOT NULL PRIMARY KEY, 
    [EmployeeName] NVARCHAR(MAX) NULL, 
    [Department] INT NULL, 
    [Telephone] NVARCHAR(MAX) NULL, 
    [Extension] NVARCHAR(50) NULL, 
    [Title] NVARCHAR(MAX) NULL, 
    [Email] NVARCHAR(MAX) NULL,
    CONSTRAINT [fk_department] FOREIGN KEY ([Department]) REFERENCES [Departments]([DepartmentID]) ON UPDATE CASCADE
)
