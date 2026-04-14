# Hello World program on the ARM Cortex A9 APU workflow

<br>
<br>
<br>

1. Create a new Vivado project as usual but select the part number 'xc7z020clg484-1' or the Zynq 7000 Evaluation kit from the boards list.
<img width="1920" height="1042" alt="image" src="https://github.com/user-attachments/assets/ec0b1937-6d65-44d6-b39d-8e3b2aeaa386" />
<br>
<br>
<br>

2. Once the project window is open, click on *Create Block Design*
<img width="561" height="557" alt="image" src="https://github.com/user-attachments/assets/f3a4e6aa-e16e-49e0-bef3-324211cb7a99" />
<br>
<br>
<br>

3. Give the design the name *hello_world_block* and click ok.
<img width="376" height="264" alt="image" src="https://github.com/user-attachments/assets/b74c1da5-f79f-444a-aaef-75c6ae95388c" />
<br>
<br>
<br>

4. Once the block design window is open, right click anywhere on the blank space in the window or click on the *+* icon in the center.
<img width="1229" height="568" alt="image" src="https://github.com/user-attachments/assets/3cb3b972-37e3-4312-ada2-e8681c2183ae" />
<br>
<br>
<br>

5. Search for the *ZYNQ7 Processing System* and select it by double clicking.
<img width="315" height="448" alt="image" src="https://github.com/user-attachments/assets/6f9fb321-93e5-4c66-be9a-7b4b2f94a7c8" />
<br>
<br>
<br>

6. The *Zynq Processing System* IP Block will be instantiated on the window.
<img width="1237" height="576" alt="image" src="https://github.com/user-attachments/assets/83bdbc05-89d4-42a7-a15f-bf963136c83d" />
<br>
<br>
<br>

7. This block is the Zynq Processing system which will help in running the program on the ARM Processor. Click on the *Run Block Automation* button.
<img width="1241" height="575" alt="image" src="https://github.com/user-attachments/assets/94e5e9de-0ed2-4797-86bf-f1c3d2b998df" />
<br>
<br>
<br>

8. The Block Automation window will pop up, for now leave the settings as they are and click ok.
<img width="1010" height="676" alt="image" src="https://github.com/user-attachments/assets/bbfec278-b64e-4aff-b229-af04f0290609" />
<br>
<br>
<br>

9. The processing system IP will now have been configured, you will be able to see the DDR and IO ports. Although this step is enough to run a hello world program, it is good practice to have a resetting mechanism with the processing system. Right click on the blank space and click on *Add IP* and select the *Processor System Reset*
<img width="310" height="441" alt="image" src="https://github.com/user-attachments/assets/845e0ef3-b680-4d6c-ac03-820207b17aa4" />
<br>
<br>
<br>

10. It will instantiate a Resetting IP block on the diagram window.
<img width="1244" height="583" alt="image" src="https://github.com/user-attachments/assets/33a3e000-3db8-4711-86d9-284e4b4739a3" />
<br>
<br>
<br>
