# BUG.WISER

Table of Contents

Content		Page
Title Page		1
Release History		2
Release Table		3
User Manual Title Page	4
Version History Page	5
Table of Contents		6

Section 1.0 Introduction	7
	Section 1.1 Welcome
	Section 1.2 System Overview
	Section 1.3 Conventions Used in this Manual	
Section 2.0 Installation	11
	Section 2.1 System Requirements
	Section 2.2 Back-Up of Distribution Disks
	Section 2.3 Installation Steps
	Section 2.4 How to Start the BugWiser System
Section 3.0 Introduction to User Interface	13
	Section 3.1 Menu System
	Section 3.2 Data Entry
	Section 3.3 Prompts
	Section 3.4 Modifying Attributes
Section 4.0 Operating Procedures	17
	Section 4.1 Create New Operation Procedures
	Section 4.2 Modify an Existing Change Item
	Section 4.3 Assess Fresh Requests 
	Section 4.4 Printing Reports
Section 5.0 Back-Up Procedures	42
Section 6.0 References	43
	Section 6.1 Error Messages
	Section 6.2 Menu Tree 	
Appendix A Glossary of Terms	48	





1.0) 	Introduction

1.1) Welcome
Welcome to the BugWiser Tracking System User Guide. We are excited to have you on board for this journey to a more efficient way of tracking issues. Being a user, by using our system, you become part of an innovative solution developed to revolutionize how software companies can handle bug tracking and enhancement requests.

The following guide is a detailed creation with the motive of providing every crucial  piece of information that may be needed when navigating and using the BugWiser system. In this document, we want you to feel confident knowing everything about the tools and what you would need to do to get maximum use out of our user-friendly system. Whether you are a software developer wanting to report a bug or a team leader who wants to monitor the progress on a list of various issues, BugWiser is here for you. This guide is intended to provide step-by-step instructions for using BugWiser's many features, ensuring the process of familiarization will be smooth and easy.

The following sections will give you step-by-step details on how to navigate the menus, report an issue, and track its progress in BugWiser. We also prepared a specific section for installation and creating backup copies of BugWiser for the user to understand all aspects of using BugWiser with ease. We're quite confident that once you use BugWiser, you will find it to be an invaluable tool in your software development process. We look forward to your feedback and suggestions as we continue to improve and enhance the BugWiser experience. Thank you for choosing BugWiser, and once again, welcome to our community.

1.2) System Overview
BugWiser is a robust, user-friendly system tailored to meet all needs related to issue tracking in a software company. It brings a considerable number of features and functionalities together in one user-friendly interface that makes the process of tracking and treating software issues seamless and efficient. Here are some key features:
Text-Based Interface:
Scrolling Terminal: Ensures a continuous display of interactions without graphical distractions.
Keyboard-Driven: All operations are performed through keyboard inputs, providing a straightforward and efficient user experience.
Navigating from Menus to Tasks:
Main Menu: Central hub for accessing various functionalities such as creating new items, editing existing items, assessing requests, and printing reports.
Sub-Menus: Detailed options for specific tasks, ensuring users can quickly navigate to the desired task.
Comprehensive Data Entry:
Guided Prompts: Assist users through data entry processes with clear instructions and format requirements.
Confirmation Steps: Ensure data accuracy by requiring users to confirm and check their inputs.
Creation and Modification of Entries:
Requester: Enter and store contact details for individuals submitting requests.
Request: Link requests to requesters, products, and change items, with an option to create a new entry to the system.
Change Item: Describe and prioritize change items associated with requests.
Product and Product Releases: Manage product information and be updated with their newest releases.
State Management for Requests:
Fresh Request, Assessed, and In-Progress States: Track the status of requests, from entry to assessment and fixed.
Assessment and Decision Making:
Request Assessment: Evaluate and decide on the status of "Fresh Request”, changing them to "Assessed" or "Cancelled" states.
Reporting Capabilities:
Active Change Items Report: Generate reports on ongoing change items.
Requesters to Inform Report: Produce lists of requesters who need updates on their requests.


	
Advantages of the BugWiser Tracking System
Simplicity and Focus:
Minimalistic Interface: The text-based, keyboard-only interface reduces complexity and distractions, allowing users to focus on essential tasks.
Ease of Use:
Menu System: Intuitive navigation through menus makes it easy for users to find and execute desired actions quickly.
Clear Prompts: Step-by-step prompts ensure users understand what information is needed and which format to provide it in.
Efficiency in Data Management:
Centralised Data Entry: Consolidates information entry and modification into a single system, reducing redundancy and improving data consistency.
Linked Entries: Associating requests with requesters, products, and change items simplifies the tracking process.
Accurate Tracking and Status Updates:
State Management: Provides visibility into the status of each request, resulting in better tracking and management of development tasks.
Assessment Functionality: Ensures that all requests are reviewed and properly categorized, which helps in prioritization and resource allocation.
Improved Communication:
Reporting: Automated reports keeps users informed about active change items and pending updates, enhancing communication and transparency between our system and the users which is our utmost priority.
Requester Information Management: Maintains accurate contact details for individuals, so they can receive timely updates and can be used to filter requests.
Structured Workflow:
Defined Processes: Clear steps for creating, modifying, and assessing entries provide a structured workflow that enhances efficiency and consistency in handling requests.

In a nutshell, the BugWiser Tracking System is at its core designed to be all-encompassing for smoothing the procedure of issue-tracking, enhancing collaboration, and improving the overall efficiency of a software development team.


1.3) Conventions Used in This Manual

To make this user guide as clear and easy to follow as possible, we have established a set of conventions that will be used throughout the manual. These conventions are designed to clarify when we are illustrating user input, system output, and other elements of interaction with the BugWiser Tracking System.
Any text displayed by the program will be in bolded Courier font.
The terminal window will be represented by a square box.
Keys on a keyboard will be represented by greater than and less than symbols, e.g., <key>
Prompts will be represented within square brackets, e.g., [Prompt].
Error messages will also be displayed in bolded Courier font e.g., "ERROR: Invalid selection".
Any text entered by the user will be in non-bolded Courier font.
Users must confirm actions by typing specific numbers or letters and pressing enter.
To select options from a menu, the user must type the corresponding number next to the menu option and press enter.
P: Displays the previous 20 items in a list. If there are no previous items, the message "NO PREVIOUS LIST ITEMS AVAILABLE" will be shown.
N: Display the next 20 items in a list. If there are no more items, the message "NO MORE LIST ITEMS AVAILABLE" will be shown.
0: Return to the Main Menu from any sub-menu or prompt.
B: Go back to the previous selection or menu.
Please note that these conventions are used consistently throughout the manual to guide your understanding and use of the BugWiser Tracking System. Following these conventions will help ensure a smooth and effective interaction with our system.








2.0) Installation

2.1) System Requirements
To use BigWiser, you will need:
A minimum of 4 GB RAM
At least 2 GB of free disk space
A processor with 1 GHz or faster
A monitor
A keyboard and mouse or equivalent input device (mouse to navigate through Windows)
An internet connection with a speed of at least 1 Mbps
Windows 10 or later
Note that BugWiser does not require any specific operating system to run, we recommend using a recent version of your operating system with all the latest updates installed for the best user experience.
2.2) Back-Up of Distribution Disks                    
We strongly recommend that you back up the BugWiser system to a secure storage device before installation. This ensures that you have a copy of the program in case the original becomes damaged or lost. Here is a typical back-up procedure:
Insert the BugWiser system disk into your computer's disk drive.
Access your system's command line interface. You can do this by: a) Starting it up, if it's not already running. b) If you're on a Windows system, start the command line interface in a new window.
Type c: and press Enter.
Type cd\ and press Enter.
Create a temporary directory by typing md tempBugWiser and press Enter.
Navigate to the newly created directory by typing cd tempBugWiser and press Enter.
Copy the contents of the BugWiser disk to the hard drive by typing copy a:\*.* c: and press Enter.
Remove the BugWiser disk from the drive and insert a blank, formatted storage device.
To create a back-up copy, type copy *.* a: and press Enter.
Remove the back-up storage device from the drive.
Delete the temporary storage by typing del *.* and pressing Enter.
Navigate back to the root directory by typing cd\ and pressing Enter.
Finally, remove the temporary directory by typing rd tempBugWiser and pressing Enter.
Remember to keep the back-up copy in a safe and secure location.

2.3) Installation Steps: 
		
BugWiser will be available on Universal Serial Buses (USBs). To install the system, follow the steps below: 
Connect the USB to the USB-C port to view the contents of the flash drive on the computer.
Navigate to the folder that contains the USB’s content, usually found under the “This PC” section. Look for an image of a flash drive labelled “BugWiser”.
Double-click on the drive to open it. You will see a folder named “BugWiser system”. This folder is important because it contains the application.
It is recommended to copy the “BugWiser system” folder and paste it in an easily accessible and memorable location. A good option is the Desktop, as it will be visible whenever the computer is turned on.
Double-click on the folder to open it, and you should see a file named BugWiser.exe. Right-click on this file and select "Run as administrator".
If a warning screen appears asking, "Do you want this app to make changes to your device?", click "Yes". This prompt is a standard security measure and is nothing to be concerned about.
	Remember to keep the back-up copy in a safe place. 

2.4) How to Start the BugWiser System

	To begin running the program, open a console window via "Command Prompt" and then press <enter>, and navigate to the directory in which you saved the folder via <cd> commands. Once in the appropriate folder enter "BugWiser.exe" to begin the program.

	




3.0)	Introductions to the User Interface

	The User Interface system in the BugWiser Tracking System will be a scrolling terminal with a text-only interface. Because this is a scrolling terminal, the screen will not be cleared. Each new text that is displayed will cause the previous text to scroll up. The actual text that is displayed in the User Interface cannot be moved, resized, or deleted (unless the source of the text is from the user’s keyboard). The text displayed by the program cannot be selected, but please note that we will be using the word “select” throughout this user manual (see section 3.2 for an explanation of the usage of “select”).


	3.1) Menu System
	To utilize the menu, the user must access it via the keyboard. The user can choose the menu option they would like to select by typing the corresponding digit next to the option followed by the <enter> key. Each option will either direct the user to a sub-menu, or prompt the user to input information. When selecting from a long list of items, the user may opt to select the menu option “Display More”. This will trigger the program to display more of the items that the user is currently viewing. Please refer to section  6.3 for the full Menu tree. The following error message will appear if the user enters a number that is not on the list:
ERROR: Invalid selection. The option you entered does not exist.


	The Main Menu will be the first menu as well as the first text that will be displayed when the program starts.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER:



	3.2)	Data Entry
	When asked to “select” an item, the user must type the number next to the menu option they would like to choose and then press <enter> on their keyboard. For example, when the user is on the Main Menu (as shown above), if the user wants to select the “Print Report” option. The user must type “4” and then press <enter>.

	In general, all inputs to the system by the user must be followed by the <enter> key for the system to register the input.

		Data entry can only be done using a keyboard. When the user is given a prompt 		by the system, the user can immediately begin typing their input—it is not necessary for 		the user to click on anything in the user interface.


	3.3)	Prompts
		There are different types of prompts that the program may output. A prompt will 		be represented by square brackets, i.e. [prompt].

1)  Selecting from a list

------Sub Menu Name-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

[Prompt]
1) [Option A]
2) [Option B]
..
..
20) [Option X]


	The user will then type in the number adjacent to their desired choice, and press <enter>. On all menus (other than the conformation question menu) the option of "0" will be available to return to the Main Menu.

== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

	
	If the user enters "P" and presses <enter>, the previous 20 items in the list will be displayed. However, if these are the first 20 items of the list, a systematic error will be shown with the message: 

NO PREVIOUS LIST ITEMS AVAILABLE


	If the user enters "N", the next 20 items in the list will be displayed. Similarly, if there are no more items, the following error will be shown:

NO MORE LIST ITEMS AVAILABLE


 	As with previous lists and sections, if the user selects "0", the system will automatically return them to the Main Menu.


            2)  Confirmation Question

Is the following information correct:
New data will be here

1) Confirm
0) Cancel
Type your selection and press ENTER:


		After the user enters new data (i.e. new product, new product release, new data, 		new requester, new issue description), the system will ask for confirmation to continue. If 	the user enters “1” , the system will submit the answer, and move on to the next menu 		item. Otherwise, if the user types “0”, the system will ignore the new data, and send the 		user back to the Main Menu. 

Note:  If the user enters an input they would like to change while creating an object, the user must continue entering the prompts and can only cancel the operation once the program continues onto the confirmation question.  


3)  Entering Data Items
	If there is data that must be manually entered then the program will prompt the user accordingly, and provide an example of the expected format.

Please enter phone number
(10-11 digits, E.g. 11234567890)


	The user is then to type in the correct information followed by pressing <enter>. Entering data in an incorrect format may result in the malfunctioning of the system. It is the users responsibility to assure the proper format of information entered as the system may or may not prevent incorrect inputs.

3.4)	Modifying Attributes
	The option of “Modify Existing” is available for Change Items that are currently in the “Assessed” or “In-Progress” state. Change Items in the “Fresh”, “Cancelled”, or “Done” state can not be modified. Once a Change Item is selected the user can modify the description, status, priority, or its anticipated fix release ID. 

	The best way to modify the data, is by navigating to option 2 in the Main Menu, where the system will redirect the user to the following sub menu:

------Modify Existing:-----
1) Change Item
B) Previous Menu
Type your selection and press ENTER:

		In this case, the user has two options: type “1” to access the fields available for 		editing, or type “0” to return to the Main Menu. Note for a new change item, the system 		will automatically generate a new unique change ID that can not be edited. 















4.0) Operating Procedures.

	Enter an input means that the user types in the input and then pressed <enter>. e.g. Enter the menu option 2.

	This section assumes the user knows how to operate the system’s menus and accurately input the data; please refer to section 3 and its following subsections for further detail on the operation of menus.
4.0.1)	Organization of Section 4
	Each subsection of section 4 (i.e. 4.1, 4.2, etc..) will explain the different operating procedures for each option in the Main Menu. The subsections for each section (i.e. 4.1.1, 4.1.2, etc…) will be the other operating procedures related to the Main Menu option chosen. 

	Each operating procedure will be a step by step explanation of different procedures a user can operate. The steps for each procedure will be enumerated—i.e. 1), 2), 3). Any subsections of a step (i, ii, iii, iv) indicate different paths a user can select when on a specific step.

Important Symbols:
☞ indicates steps where the user must enter an option displayed in the menu. If the user enters a non existing menu option, an error message will occur (refer to section 6.1.1).

⚠︎ indicates steps where the user input could trigger an error message (refer to section 6.1). The description of the error will be listed in greater detail at the bottom of the operating procedure.
4.0.2)	Formatting of the Operating Procedures
	Courier font (i.e. Courier), inside of a box will represent any text that is displayed on the screen. There will be two types of text:

-Any text that is displayed and outputted by the program will be represented by 	bolded Courier font. E.g:

Bolded represents what the system will output.




-Any text that is inputted by the user and then displayed onto the screen will be represented by non bolded Courier font. E.g:

Non bolded represents what a user may input.


	Italicized Times New Roman font surrounded by two asterisks will represent 	notes/comments for the reader of this User Manual; these notes are for further context.

** Enter note for the reader ** 

Note: The system does not display these notes.

	There will be some text shown in the User Manual that will not be displayed in the program verbatim. Square brackets will be used to indicate places in which text is displayed but may vary throughout the program.The content inside the square brackets are notes as to what will be displayed. There may also be examples of what a user has input.

[prompt]
[user’s option]

Note: The system does not display the above text verbatim, “John Doe” is a placeholder 		for information already inputted and stored in the system.

Important: Each operating procedure will have the following format: 

1) The instructions for the operating procedure will be typed above the box that represents the system display.

------Create New:-----
1) Request
2) Requester
3) Product
4) Product Release
0) Return to Main Menu
B) Previous Menu
0) Quit
Type your selection and press ENTER: 1 
** the input above will show what the user should enter** 

	
	 * The format for the Bugwiser's procedures was selected by Pixel Pioneers' 	software team because it is simple to use and flows well, reducing confusion and 		ultimately improving the user experience.

Notes on the examples for sample data:
	The sample data displayed in the screenshots of the operating procedures will appear in a specific format to represent the data that will be displayed. 
Sample data using characters {A..Z, a..z, 0..9} will be displayed as underlined “x”s:
This includes spaces, periods and other characters that can be inputted by a keyboard.

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

Note: The maximum possible length of the data will be represented by the number of 		characters displayed.

	Sample data using digits {0..9} will be displayed as underlined “d”s:

ddddddddddd

Note: The maximum possible length of the data will be represented by the number of 		characters displayed.

Examples of sample data may also be shown in this User Manual. e.g:

1) John Doe

Note: The system does not display the above text verbatim, “John Doe” is a placeholder 		for information already inputted and stored in the system.

Dots between menu options represent more sample data that will be displayed. In the actual program, lists will be displayed starting from 1 item, up to 20 items. For the purposes of this User Manual, dots have replaced redundant sample data to save space.

2) xxxxxxxxxxxxxxxxxxx
..
..
20)xxxxxxxxxxxxxxxxxxxx


4.0.4)	 List of Operating Procedures
4.1.1)  Creating a new Requester
4.1.2)  Creating a Request
4.1.3)  Creating a new Change Item 
4.1.4)  Creating a new Product
4.1.5)  Creating a new Product Release
4.2.0)  Modifying an existing Change Item
4.2.1)  Modifying the Description of a Change Item
4.2.2)  Modifying the Status of a Change Item
4.2.3)  Modifying the Priority of a Change Item
4.2.4)  Modifying the Anticipated Release ID of a Change Item
4.3.0)  Assess Fresh Requests
4.4.0)  Query a Change Item
4.5.0)  Print Report
4.5.1)  Print a list of all active Change Items
4.5.2)  Print a list of all Requester’s to be informed of an implemented Change 	  	Item

4.1) Create New Operating Procedures 

☞ 1)   Enter 1 to select the “Create New” option from the main menu.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER: 1

4.1.1)	 Creating a new requester
	1)   Refer to step 1 in section 4.1.0.

⚠︎☞ 2)  Enter 2 from the sub-menu to start creating a new requester.

------Create New:-----
1) Request
2) Requester
3) Product
4) Product Release
0) Return to Main Menu
B) Previous Menu
Type your selection and press ENTER: 2


⚠︎ 3)  Enter the phone number of the requester.

Please enter phone number:
(10-11 digits no dashes, E.g. 11234567890)
ddddddddddd


⚠︎ 4)  Enter the full name of the requester.

Please enter full name:
(1-30 characters, E.g. Jane Doe)
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


⚠︎ 5)  Enter the email of the requester.

Please enter email:
(1-24 characters, E.g. janedoe@gmail.com)
xxxxxxxxxxxxxxxxxxxxxxxx


⚠︎ 6)  Enter the department of the requester.

If applicable, please enter department:
(0-12 characters, E.g. Marketing)
xxxxxxxxxxxx



7) Review the previous inputs and either choose to confirm or cancel the process.

Is the following information correct:
[phone number entered by user]
[name entered by user]
[email entered by user]

1) Confirm
0) Cancel
Type your selection and press ENTER:




☞ i)  Verify information and confirm.
1) Confirm
0) Cancel
Type your selection and press ENTER: 1

Requester has been added, returning to the Main Menu.


☞ ii)  Reject information and cancel.

1) Confirm
0) Cancel
Type your selection and press ENTER: 0

Operation cancelled, returning to the Main Menu.




 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 1)
- Disk is Full (refer to section 6.1.5)
- When doing any creation procedures, disk space is needed to store the items.
  ⚠︎ 3)
- Data Range (refer to section 6.1.2)



- Data Format (refer to section 6.1.3)
- Phone Number must have a minimum of 10 characters to a  maximum of 11 characters. 

- Phone Number must be entered as digits 
  ⚠︎ 4)
- Data Range (refer to section 6.1.2)


- Name must have a minimum of 1 character to a  maximum of 30 characters. 
  ⚠︎ 5)
- Data Range (refer to section 6.1.2)


- Key Uniqueness (refer to section 6.1.4)
- Email must have a minimum of 1 character to a  maximum of 24 characters. 

- Email must be unique
  ⚠︎ 6)
- Data Range (refer to section 6.1.2)
- Department must have a maximum of 12 characters. 

	
	4.1.2)	 Creating a request
	1)   Refer to step 1 in section 4.1.0.

⚠︎☞ 2)  Enter 1 from the sub-menu to start creating a new request.

------Create New:-----
1) Request
2) Requester
3) Product
4) Product Release
B) Previous Menu
Type your selection and press ENTER: 1


3) Search for the email of the requester.

☞ i)  If the email of the requester is found, input the corresponding menu option.

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Requester
1) [Requester]
2) [Requester]
..
..
20)[Requester]
C) Create New Requester
Type your selection and press ENTER: [user option]


	☞ ii) If the requester’s email is not found, select “Create a new Requester” (see 			section 4.1.1).

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Requester
1) [Requester]
2) [Requester]
..
..
20) [Requester]
C) Create New Requester
Type your selection and press ENTER: C


	☞ 4) Select the product which the requester is inquiring about.

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Product
1) [Product]
2) [Product]
..
..
20) [Product]
Type your selection and press ENTER: [user’s option]


	☞ 5) Select the product release ID which the requester is inquiring about.

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Release ID
1) [Release ID]
2) [Release ID]
..
..
20) [Release ID]
Type your selection and press ENTER: [user’s option]


6) Select a change item, or create a new change item.

	☞ i) Select the appropriate change item.

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please select a Change Item
1) [Description]
2) [Description]
..
..
20) [Description]
2) Create a new Change Item
Type your selection and press ENTER: [user’s option]


	⚠︎ ☞ ii) If none of the descriptions of the Change Items are applicable to the 		request’s issue, Select “Create New Change Item” by entering C  (see section 		4.1.3).	

------Create New: Request-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please select a Change Item
1) [Description]
2) [Description]
..
..
20) [Description]
C) Create a new Change Item
Type your selection and press ENTER: C


	

	⚠︎ 7) Input the current date.

Please enter the date of request/current date:
(yyyy-mm-dd, E.g. 2000-11-22)
dddd-dd-dd

	
	8) Depending on the success of the creation of the Request, a confirmation message or an 	error message will be displayed and the user will be directed back to the Main Menu.

	i) In the case of successful Request creation:	

Request has been added, returning to the Main Menu.


		ii) In the case of a failed Request creation:

Failed to add request, returning to the Main Menu.




 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Disk is Full (refer to section 6.1.5)
- When doing any creation procedures, disk space is needed to store the items.
  ⚠︎ 6ii)
- Disk is Full (refer to section 6.1.5)
- When doing any creation procedures, disk space is needed to store the items.
  ⚠︎ 7)
- Data Range (refer to section 6.1.2)

- Data Format (refer to section 6.1.3)


- Dates must be 10 characters.

- Dates must follow a specific format. i.e. (yyyy-mm-dd).

	4.1.3)	 Creating a new Change Item
		Note: 
		A new Change Item can only be created while creating a new Request. 				Only create a new Change Item if none of the existing Change Items have the 			same description as the issue the Requester is inquiring about (i.e. The Change 			Item does not exist.). 



	1) Follow steps 1-6ii in section 4.1.2.
	
	2) Input the description of the change item.

Please enter a brief description:
(1-30 characters)
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


	☞ 3) Input the priority of the change item.

Please select a Priority (1-5, 5 being the highest):
1) 1
2) 2
3) 3
4) 4
5) 5
Type your selection and press ENTER: [user’s option]


	4) Verify the new change item.

	☞ i) Confirm the new change item.

Is the following information correct:
[Product] [Release ID]
[user’s description]

1) Confirm
0) Cancel
Type your selection and press ENTER: 1

		
		i) Text will display to confirm that the Change Item was created.

Change Item created, returning to Main Menu


	☞ ii) Cancel the new change item.	

Is the following information correct:
[Product] [Release ID]
[user’s description]

1) Confirm
0) Cancel
Type your selection and press ENTER: 0

	
	ii) Text will display to confirm that the Change Item was cancelled.

Operation cancelled, returning to Main Menu

	

 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Data Range (refer to section 6.1.2)
- Description must have a minimum of 1 character to a  maximum of 30 characters. 

4.1.4)	 Creating a new Product
	1)   Refer to step 1 in section 4.1.0.

	⚠︎☞ 2) Enter 3 from the sub menu to create a new product.

------Create New:-----
1) Request
2) Requester
3) Product
4) Product Release
0) Return to Main Menu
Type your selection and press ENTER: 3


	⚠︎ 3) Enter a product name.

Please enter new product name:
(1-10 characters, E.g. Pear)
xxxxxxxxxx


4) Review information.

☞ i)  Verify information and confirm.	

Is the following information correct:
[user’s product name]

1) Confirm
0) Cancel
Type your selection and press ENTER: 1


		i) Text will display to confirm that the Product was added.

Product has been added, returning to Main Menu


☞ ii)  Reject information and cancel.

Is the following information correct:
[user’s product name]

1) Confirm
0) Cancel
Type your selection and press ENTER: 0


		ii) Text will display to confirm that the operation to add a Product was cancelled.
.
Operation cancelled, returning to Main Menu



 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Disk is Full (refer to section 6.1.5)
- When doing any creation procedures, disk space is needed to store the items.
  ⚠︎ 3)
- Data Range (refer to section 6.1.2)


- Key Uniqueness (refer to section 6.1.4)
- Product Names must have a minimum of 1 character to a maximum of 30 characters.

- No duplicate Product Names. A Product Name must be unique. 

4.1.5)	 Creating a new Product Release
	1)   Refer to step 1 in section 4.1.0.

	⚠︎☞ 2) Enter 4 from sub menu to create a new Product Release.

------Create New:-----
1) Request
2) Requester
3) Product
4) Product Release 
0) Return to Main Menu
Type your selection and press ENTER: 4


	☞ 3) Select the product for which the Product Release is being created.	

------Create New: Product Release-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Product
1) [Product]
2) [Product]
..
..
20) [Product]
Type your selection and press ENTER: [user’s option]


	⚠︎ 4) Enter the desired release ID.

Please enter product Release ID:
(1-8 characters)
xxxxxxxx


	⚠︎ 5) Enter the release date of the Product Release.

Please enter product Release Date:
(yyyy-mm-dd, E.g. 2000-11-22)
dddd-dd-dd

	6) Verify the new product release.
		☞ i) Confirm the new product release.

Is the following information correct:
[Product] [Release ID entered by user]
[Date entered by user]

1) Confirm
0) Cancel
Type your selection and press ENTER: 1


		i) Text will display to confirm that the operation to add a Product Release was 			created.

Product Release created, returning to create request


	☞ ii) Cancel the new change item.

Is the following information correct:
[Product] [Release ID entered by user]
[Date entered by user]

1) Confirm
0) Cancel
Type your selection and press ENTER: 0

		

		ii) Text will display to confirm that the operation to add a Product Release was 			cancelled.

Operation cancelled, returning to Main Menu



 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Disk is Full (refer to section 6.1.5)
- When doing any creation procedures, disk space is needed to store the items.
  ⚠︎ 4)
- Data Range (refer to section 6.1.2)
- Release IDs must have a minimum of 1 character to a maximum of 8 characters.
  ⚠︎ 5)
- Data Range (refer to section 6.1.2)

- Data Format (refer to section 6.1.3)


- Dates must be 10 characters.

- Dates must follow a specific format. i.e. (yyyy-mm-dd).


4.2.0) Modify an existing Change Item
☞ 1) Enter 2 to select the “Modify Existing” option from the Main Menu.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER: 2


☞ 2) Enter 1 from the sub-menu to modify a change item.

------Modify Existing:-----
1) Change Item
B) Previous Menu
Type your selection and press ENTER: 1


☞ 3) Select the state of the change item the user intends to modify.

------Modify Existing: Change Item-----
1) All
2) Assessed
3) In-Progress
0) Return to Main Menu
B) Previous Menu
Type your selection and press ENTER: 1


☞ 4) Select the change item.

------Modify Existing: Change Item-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please select a Change Item
1) [Description]
2) [Description]
..
..
20) [Description]
Type your selection and press ENTER: [user’s option]


☞ 5) The current information of the change item will be displayed. Select the attribute to modify: (refer to subsections depending on what you would like to modify).

------Modify Existing: Change Item-----
Description of Change Item
Change ID of Change Item
Priority of Change Item
Status of Change Item
Anticipated Release ID

Please select an attribute to modify
1) Description
2) Status
3) Priority
4) Anticipated Fix Release ID
0) Return to Main Menu
B) Previous Menu
Type your selection and press ENTER: [user’s option]

4.2.1)	 Modifying the Description of a Change Item
☞ 1) Follow Steps 1-5 in section 4.2.0. Once at Step 5 of section 4.2.0., Enter 1 	to select the “Description” option to modify the description.

Type your selection and press ENTER: 1



⚠︎ 2) Enter your new description.

Please enter revised description:
(1-30 characters)
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx


3) Verify the new description.

Is the following information correct:
[Description entered by user]

1) Confirm
0) Cancel
Type your selection and press ENTER:


☞ i) To Confirm the new description, enter 1.
1) Confirm
0) Cancel
Type your selection and press ENTER: 1

		
		i) Text will display to confirm that Description has been updated.

Description updated, returning to Modify Existing


☞ ii) To Cancel the new description, enter 0.

1) Confirm
0) Cancel
Type your selection and press ENTER: 0

		
		ii) Text will display to confirm that the Description update has been cancelled.

Operation cancelled, returning to Modify Existing





 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Data Range (refer to section 6.1.2)
- Descriptions must have a minimum of 1 character to a maximum of 30 characters.

4.2.2)	 Modifying the Status of a Change Item
☞ 1) Follow Steps 1-5 in section 4.2.0. Once at Step 5 of section 4.2.0, Enter 2 to select the “Status” option to modify the description.

Type your selection and press ENTER: 2


☞ 2) Select a new Status.

------Modify Existing: Change Item-----
Please select a new Status
1) In-Progress
2) Cancelled
3) Done

0) Return to Main Menu
B) Previous Menu
Type your selection and press ENTER: [user’s option]


3) After selecting, a confirmation message will appear.

Status updated, returning to Modify Existing

4.2.3)	 Modifying the Priority of a Change Item
☞ 1) Follow Steps 1-5 in section 4.2.0. Once at Step 5 of section 4.2.0, Enter 3 to select the “Description” option to modify the description.

Type your selection and press ENTER: 3


☞ 2) Select a new Priority.

------Modify Existing: Change Item-----
Please select a Priority (1-5, 5 being the highest)
1) 1
2) 2
3) 3
4) 4
5) 5
0) Return to Main Menu
B) Previous Menu
Type your selection and press ENTER: [user’s option]


3) After selecting, a confirmation message will appear.

Priority updated, returning to Modify Existing Menu


4.2.4)	 Modifying the Anticipated Release ID of a Change Item
☞ 1) Follow Steps 1-5 in section 4.2.0. Once at Step 5 of section 4.2.0, Enter 4 to select the “Description” option to modify the description.

Type your selection and press ENTER: 4


⚠︎ 2) Enter the Anticipated Release ID.

Please enter Anticipated Release ID:
(1-8 characters)
xxxxxxxx

3) Verify the new Anticipated Release ID.

Is the following information correct:
[Anticipated Release ID entered by user]

1) Confirm
0) Cancel
Type your selection and press ENTER: 0


☞ i) To Confirm the Anticipated Release ID, enter 1.
1) Confirm
0) Cancel
Type your selection and press ENTER: 1

		
		i) Text will display to confirm that Anticipated Release ID has been updated.

Anticipated Release ID updated, returning to Modify Existing


☞ ii) To Cancel the Anticipated Release ID, enter 0.

1) Confirm
0) Cancel
Type your selection and press ENTER: 0

		
		ii) Text will display to confirm that the Anticipated Release ID update has been 			cancelled.

Operation cancelled, returning to Modify Existing



 Step
 Possible Input Error
 Detailed Description
  ⚠︎ 2)
- Data Range (refer to section 6.1.2)
- Anticipated Release IDs must have a minimum of 1 character to a maximum of 8 characters.



4.3)	Assess fresh requests
	☞ 1) Enter 3 from Main Menu.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER: 3


☞ 2) A list of all Change Items in the "Fresh" stat will be displayed, select a Change Item.

------Assess Change Item-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please select a Change Item
1) [Description]
2) [Description]
..
..
20) [Description]
Type your selection and press ENTER: [user’s option]


☞ 3) The current information of the change item will be displayed along with the options to move it into the "Assessed" or "Cancelled" state.	

[Description of Change Item]
[Change ID of Change Item]
[Priority of Change Item]
[Status of Change Item]

Please select Status
1) Assessed
2) Cancelled
B) Previous Menu
Type your selection and press ENTER: [user’s option]


	4) A confirmation text will appear then send the user back to the Main Menu.

Status Updated. Returning to Main Menu.


4.4)	Query Change Items
	☞ 1) Enter 4 from Main Menu.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER: 3


☞ 2) Enter 1 to search for a Change Item

------Query:-----
1) Change Item
B) Previous Menu
Type your selection and press ENTER: 1


☞ 3) The current information of the change item will be displayed along with the options to move it into the "Assessed" or "Cancelled" state.	

------Query:-----
[Description of Change Item]
[Change ID of Change Item]
[Priority of Change Item]
[Status of Change Item]

Please select Status
1) Assessed
2) Cancelled
B) Previous Menu
Type your selection and press ENTER: [user’s option]


	4) A confirmation text will appear then send the user back to the Main Menu.

Status Updated. Returning to Main Menu.



4.5)  Print Report
☞ 1) Enter 5 from Main Menu.

======Main Menu======
1) Create New
2) Modify Existing
3) Assess
4) Query
5) Print Report
0) Quit
Type your selection and press ENTER: 4

4.5.1)	 Print a list of all active Change Items.
☞ 1) Enter 1 to print a list of all Change Items that are active (Fresh Request, Assessed, In-Progress).

-----Print Report-----
Please select the type of report you would like to print
1) List of all active Change Items
2) List of all Requesters to be Informed
B) Previous Menu
Type your selection and press ENTER: 1


	☞ 2) A list of all active Change Items will be displayed onto the screen.

--------------------------------Print Report: Active Change Items-------------------------------
   Product:   Description:                     Change ID:   Priority:          State:   Anticipated                                                                                                                      
                                                                                         Release ID:
1) Pear       Loading slowly after input             1234           3        Assessed         v.3.1
2) [Product]  [Description]                   [Change ID]  [priority]         [state]  [Ant.Rel.ID]
x) xxxxxxxx   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       dddddd           d   xxxxxxxxxxxxx      xxxxxxxx                                                    
..
..
---------------------------------------------------------------------------------------------------
0) Return to Main Menu 
Type your selection and press ENTER:

	
☞ 3) After viewing the list, the user can enter 0 to return to the Main Menu.

0) Return to Main Menu
Type your selection and press ENTER:0


4.5.2)	 Print a list of all Requesters to be informed of an implemented Change Item
☞ 1) Enter 2 to print a list of all the Requesters that need to be informed about a particular change.

-----Print Report-----
Please select the type of report you would like to print
1) List of all active Change Items
2) List of all Requesters to be Informed
B) Previous Menu
Type your selection and press ENTER: 2


	☞ 2) Select the Product the Change Item is regarding.

-----Print Report: Requesters to be Informed-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please Select a Product
1) [Product]
2) [Product]
..
..
20)[Product]
Type your selection and press ENTER: [user’s option]


	☞ 2) Select the Change Item.

-----Print Report: Requesters to be Informed-----
== Please type 0 to go back to the Main Menu ==
== P for the previous 20 items ==
== N for the next 20 items ==
== B to go back to the previous selection == 

Please select a Change Item
1) [Description]
2) [Description]
..
..
20) [Description]
Type your selection and press ENTER: [user’s option]



	☞ 3) A list of all the Requesters that need to be informed about said Change Item.

--------------------Print Report: Requesters to be Informed--------------------
Change ID:      Description:                        Released in:  
dddddd          xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      xxxxxxxx       
                                                                                    
   Requester:                        Email of Requester:         Phone Number:                                                           
1) John Doe                          johndoe@outlook.com         15555558888       
2) [Name]                            [Email]                     [Phone Number]
x) xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    xxxxxxxxxxxxxxxxxxxxxxxx    ddddddddddd   
..
..
-------------------------------------------------------------------------------
0) Return to Main Menu 
Type your selection and press ENTER:

	

5.0) Backup Procedures
It is recommended that you backup your data files every day to prevent loss or damage to your data. To back up the data files containing your bugs, enhancements, and user information in BugWiser, follow these steps:
Access your system's command line interface.
Navigate to the directory where BugWiser is installed by typing cd BugWiser and pressing Enter.
Insert a blank storage device into the appropriate slot.
Type copy datafiles and press Enter. The files will be transferred to your storage device.
To restore the back-up copies, ensure you are in your system's command line interface and follow these steps:
Type cd BugWiser and press Enter to navigate to the directory where BugWiser is installed.
Insert the storage device containing the backup into the appropriate slot.
Type copy d:\*.* datafiles and then press Enter. 
The data files will be transferred from your storage device to the hard drive.























6.0) Reference

	6.1) Error Messages

	In some cases, the user input can cause error messages to appear. Section 6.1 will list out the possible error messages that occur and why.

6.1.1) Invalid Menu Selection
	“Invalid Menu Selection” occurs when the user inputs a character that is not registered as a valid, existing menu option displayed. When a user is asked to select an item/option from an ordered menu, they must only enter an option that is displayed by the program.

1) The “Invalid Menu Selection” error message will appear:
ERROR: Invalid selection. The option you entered does not exist.


2) After the “Invalid Menu Selection” error message appears, the user will be prompted to re-enter a valid menu option. The user can then enter a menu option again.
Please select a valid option: [valid user option]



6.1.2)	Invalid Data Range
	When the system asks to enter an input, if the input the user enters does not meet the minimum and maximum requirements, the “Invalid Data Range” error message will appear.

1) The “Invalid Data Range” error message will appear (with its respective numbers):
ERROR: Invalid data range.


2) After the “Invalid Data Range” error message appears, the original prompt that the user was asked to input will appear again. The user must re-enter a valid input that meets the range of the minimum and maximum character requirements the prompt displays.
[Original Prompt]
[user enters a valid input]


	

	6.1.3)	Invalid Data Format

	When the system asks to enter an input, if the input the user enters does not follow the proper format, the “Invalid Data Format” error message will appear.
	
1) The “Invalid Data Format” error message will appear:
ERROR: Invalid data format.


2) After the “Invalid Data Format” error message appears, the original prompt that the user was asked to input will appear again. The user must re-enter a valid input that follows the formatting requirements the prompt displays.
[Original Prompt]
[user enters a valid input]



6.1.4)	Key Uniqueness
	Some inputs from the user need to be unique; there cannot be a duplicate input already registered in the system. In the case that the user input is a duplicate—that is, the input already exists—then the “Key Uniqueness” error message will appear.

1) The “Key Uniqueness” error message will appear:
ERROR: Already Exists.


2) After the “Key Uniqueness” error message appears, the user may choose to re-enter a non-existing item, or go back to the main menu
1) Re-enter
0) Main Menu
Make your selection and press ENTER: 

	
☞ i) To Re-enter, enter 1. The original prompt that was asked will appear again.

Type your selection and press ENTER: 1


☞ ii) To return to the Main Menu, enter 0. The user will be sent back to the Main Menu.


Type your selection and press ENTER: 0



6.1.5)	Disk Space is Full
	This system stores information the user inputs. In the case that the hard disk becomes full and the system can no longer store new information, the “Disk Space is Full” error message will appear.

1) The “Disk Space is Full” error message will appear:
ERROR: Disk Space is Full. Operation was not completed.


2) The system will send the user back to the Main Menu.


	When the program is started, the Main Menu will display:
	======Main Menu======
	1) Create New
	2) Modify Existing
	3) Assess
	4) Query
	5) Print Report
	0) Quit

Selecting 1 in the Main Menu will display:

	------Create New:-----
	1) Request
	2) Requester
	3) Product
	4) Product Release
	0) Return to Main Menu

Selecting 2 in the Main Menu will display:

	------Modify Existing:-----
	1) Change Item
	0) Return to Main Menu

Selecting 3 in the Main Menu will display:

	------Assess Change Item-----
	== Please type 0 to go back to the Main Menu ==
	== P for the previous 20 items ==
	== N for the next 20 items ==
	== B to go back to the previous selection == 

	Please select a Change Item
	1) [Description]
	2) [Description]
	..
	..
	20) [Description]

Selecting 4 in the Main Menu will display:

-----Print Report-----
Please select the type of report you would like to print
1) List of all active Change Items
2) List of all Requesters to be Informed
B) Previous Menu

Selecting 1 from Modify Existing will display:

	------Modify Existing: Change Item-----
	1) All
	2) Assessed
	3) In-Progress
	0) Return to Main Menu
B) Previous Menu
Appendix A
Glossary
	
Terms—composite—used in the dictionary:
	Any = *any character which can be input at keyboard*
	Character = (“A” | “B” | “C” | … | “Y” | “Z” |  "a" | "b" | "c" | … | “y” | “z” )
	Digit = ( "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" )

Footnote for additional information on a word/subject:

italicized = search for the word in the dictionary
* = search in the glossary of the appendix.

Anticipated Fix Release ID - An attribute of the Change Item object. This attribute lists 		the Release ID that is the anticipated release for when the 		fix will be completed. Follows the same format as the 		Release ID attribute.

Assessed -  A state option for the attribute Status. “Assessed” is an option available when 	setting the “Status” of the Change Item object. It indicates that the issue—the 	Change Item object as well as the request—has been looked over and 			assessed by a staff* member and approved as a valid request/issue.

Cancelled - A state option for the attribute Status. “Cancelled” is an option available 		when setting the “Status” of the Change Item object. It indicates that the 		issue in question has been deemed invalid or redundant and has been 		cancelled by a staff* member. 
	
Change ID - 	An integer attribute that is automatically applied when creating a Change 				Item. Each new Change ID integer will be incremented. It is used as a key 				for a specific request as well as the key for the Change Item itself. The 				BNF is: digit {digit}5 

Change Item - An object created to store the actual bug/feature that is being requested to 
change. A change item consists of its Change ID, status, a description, the product name, and an optional field for the anticipated fix release ID.

Date of Request -  An attribute written under the Request object. It lists the date that the 		request in question was created. Follows the format of yyyy-mm-dd 		(e.g. 2024-05-20)

Description - 	An attribute under the Request object and the Change Item object. The 
		Description describes the issue in question. The BNF of a Description is: 			any {any}29

Done -  A state option for the attribute Status. “Done” is an option available when setting 		the “Status” of the Change Item object. It indicates that the issue in question has 		been fixed/completed and is ready to be released, or it has already been released.

Email - An attribute of the Requester object that stores the email address of the requester. 	The BNF is: any {any}23 

Fresh Request - A state option for the attribute Status. “Fresh Request” is an option 		available when setting the “Status” of the Change Item object. It 		indicates that the issue is a newly created Change Item that has recently 	been requested and not yet assessed.

In-Progress -  A state option for the attribute Status. “In-Progress” is an option available 		when setting the “Status” of the Change Item object. It indicates that the 		issue/request in question is currently being worked on by staff* members.

Invalid/Invalid input - When an input is invalid, this can be referring to any of 			the following:
A syntax error.
The input is not following the correct format.
The input is not within its allotted character limit.
A duplicate when duplicates are not allowed.
Does not exist when the input should have an existing option to choose from.
A non ASCII character is inputted. (i.e. a different language).

Item - Is an umbrella term that can be referring to any of the following:
Options on a menu.
Information that is displayed.
Program objects and their attributes (i.e. Product, Request,. etc..)

Name - An attribute of the Requester object that stores the name of the requester. The 		BNF is: any {any}29 

Phone Number - An attribute of the phone number of the requester. A phone number 		will consist of 10-11 digits. It will follow the format: 17781234567 

Priority - An attribute listed under the Request object. This attribute is a digit from 1-5 		that indicates its priority; 5 being the highest priority and 1 being the lowest 		priority.

Product -  An object created to store the various products added to the system. This 		object contains the product name.

Select - When a user “selects” an option in the user interface, the user is inputting 			the menu number that corresponds with the menu option they would like to 		choose and then pressing the <enter> key. This requires the user to input the 		number using their keyboard.

State/Status - Both refer to the Status of a Change Item, (i.e. “Done”, “Cancelled”, etc.)

User -  A user is referring to any person that is using the system and is interacting 			with the User Interface (e.g. a staff member.)
