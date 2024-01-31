  <h1>COVID-19 Vaccination System in C++</h1>

  <h2>Introduction</h2>

  <p>In response to the COVID-19 pandemic, this console-based C++ application facilitates the efficient distribution and administration of vaccines. The system encompasses various modules, including Super Admin, Admin, Doctor, Front Desk Officer (FDO), Government Official, and Citizen, ensuring a comprehensive and streamlined vaccination process.</p>

  <h2>Modules</h2>
  <h3>Super Admin</h3>

  <p>The Super Admin has CRUD capabilities for all user accounts, providing essential administrative control.</p>

 <h3> Admin</h3>
Admins procure vaccines locally and internationally, manage warehouse facilities, establish vaccination centers based on population ratios, and oversee daily vaccine distribution.

<h3>Doctor</h3>
Assigned to vaccination centers, doctors assess citizens' vital stats, including blood pressure, oxygen levels, and glucose levels, logging the information into the system.

<h3>FDO (Front Desk Officer)</h3>
FDOs manage citizen eligibility, assign counters based on availability, and oversee vaccine administration.

<h3>Government Official</h3>
Government officials access detailed reports and statistics, including vaccination percentages, city-wise data, district-wise population percentages, expenditure on vaccines, and various filters for patient analysis.

<h3>Citizen</h3>
Citizens register, undergo eligibility checks, receive confirmations, and can view their vaccination history, including administered vaccines and scheduled dates.


  <h2>Requirements</h2>

  <ul>
        <li>Unique login credentials stored securely in encrypted .txt files.</li>
        <li>Vaccine information includes type, name, ID, doses, price, and batch ID.</li>
        <li>Warehouse details include name, location, and capacity.</li>
        <li>Batch information includes vaccine ID, supplier ID, and expiry date.</li>
        <li>Every class involving a person inherits from the "PERSON" class with common attributes.</li>
  </ul>

   <h2>User Sign Up/Login</h2>

  <ul>
        <li>Citizens sign up with unique details, undergo eligibility checks, and receive confirmation notifications.</li>
        <li>Login credentials for all user types (Super Admin, Admin, Doctor, FDO, Government Official, Citizen) are unique and securely stored.</li>
    </ul>

   <h2>File Structure</h2>
    The code is in 3 file structure.
    "Source.cpp" file is the main file.<br>
    "Header.cpp" file contains all the classes and methods definations.<br>
    "Header.h" file contains all the classes and methods declarations.
  <h2>Screenshots</h2>
