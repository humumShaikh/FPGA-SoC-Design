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

11. Now connect the *Processor System Reset* IP's *slowest_sync_clk* with the *ZYNQ7 Processing System* IP's *M_AXI_GP0_ACLK* as shown in the diagram.
<img width="1241" height="576" alt="image" src="https://github.com/user-attachments/assets/e3525d26-2f36-4d71-9834-d468f27d31c8" />
<br>
<br>
<br>

12. Now click on the *Run Connection Automation* button.
<img width="1241" height="580" alt="image" src="https://github.com/user-attachments/assets/d0920d9f-c02f-4f21-8822-6c9d177df8de" />
<br>
<br>
<br>

13. Select the *All Automation* option as shown and click on ok.
<img width="1021" height="694" alt="image" src="https://github.com/user-attachments/assets/b93db0cb-2bfd-43ae-ac04-0a61ae5b7178" />
<br>
<br>
<br>

14. The result should look like as shown in this image.
<img width="1240" height="580" alt="image" src="https://github.com/user-attachments/assets/4560e32f-50b5-4c9d-b45f-aae49f51e56b" />
<br>
<br>
<br>

15. Click on the *Regenerate Layout* button as shown.
<img width="1240" height="584" alt="image" src="https://github.com/user-attachments/assets/dc8334cc-925f-433a-8c10-f88693686f61" />
<br>
<br>
<br>

16. Now click on the *Validate Deisng* button.
<img width="1243" height="584" alt="image" src="https://github.com/user-attachments/assets/e8ab5024-459b-4beb-bd81-a9c3191a2710" />
<br>
<br>
<br>

17. The design validation must be successful and then click on ok.
<img width="532" height="161" alt="image" src="https://github.com/user-attachments/assets/64e7954b-c9c9-4fe5-a3fa-3cba50a5ef40" />
<br>
<br>
<br>

18. Now save the design by pressing 'ctrl+s'

19. Now go to the sources tab and look for this block design under the drop down arrow of the *Design Sources*
<img width="691" height="649" alt="image" src="https://github.com/user-attachments/assets/3c1da700-9b8f-4c34-8f3d-b92c1cb8f908" />
<br>
<br>
<br>

20. Right click it and select the *Create HDL Wrapper* option and then click ok on the following pop-up.
<img width="527" height="289" alt="image" src="https://github.com/user-attachments/assets/da69273a-f517-49d4-9528-e0be1417258e" />
<br>
<br>
<br>

21. The wrapper is like a top module for the design. Once the wrapper is created you can see it in the window.
<img width="699" height="627" alt="image" src="https://github.com/user-attachments/assets/8fad73c7-5936-4935-9061-348a161abf94" />
<br>
<br>
<br>

22. Now in the *Flow Navigator* click on the *Generate Bitstream* button.
<img width="408" height="850" alt="image" src="https://github.com/user-attachments/assets/d6ccae92-d977-477a-ad9c-a652a83d858d" />
<br>
<br>
<br>

23. Click on yes if vivado asks you that there are no implementation or synthesis and then in the next pop-up select the number of jobs to maximum available for you and click ok.
<img width="490" height="347" alt="image" src="https://github.com/user-attachments/assets/04bc6cde-ce25-4da6-bd05-7885839d1d8a" />
<br>
<br>
<br>

24. This process will take quite a good amount of time, also depending on your system. Wait until the bitstream is generated and this pop-up shows up.
