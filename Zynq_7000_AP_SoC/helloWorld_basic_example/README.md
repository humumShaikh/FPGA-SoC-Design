# Hello World program on the ARM Cortex A9 APU workflow

<br>
<br>
<br>

*Note - We are using the Vivado and Vitis IDE 2023.1 as it is the most convenient and bug free version*
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

24. This process will take quite a good amount of time, also depending on your system. Wait until the bitstream is generated and this pop-up shows up., click on cancel, you may view the implemented design or the reports if you want.
<img width="393" height="338" alt="image" src="https://github.com/user-attachments/assets/31c1d114-eec2-4969-b92f-f37aea837d58" />
<br>
<br>
<br>

25. Now on the top left, click on *File* and go to the *Export* option and then select the *Export Hardware*
<img width="816" height="684" alt="image" src="https://github.com/user-attachments/assets/efe66502-b2d6-4b1f-8cc7-fac224679c08" />
<br>
<br>
<br>

26. Click *Next* and then select the *Include Bitstream* option and click *Next*
<img width="809" height="682" alt="image" src="https://github.com/user-attachments/assets/41ccc802-4942-491e-8061-dbaf580919e1" />
<br>
<br>
<br>

27. Now give the file a name you want and a location, would recommend to leave as it is and click *Next*
<img width="811" height="680" alt="image" src="https://github.com/user-attachments/assets/e03af76e-517f-47ab-bc74-cc20eb0d97f3" />
<br>
<br>
<br>

28. Click the *Finish* button.
<img width="809" height="678" alt="image" src="https://github.com/user-attachments/assets/31a77777-7e23-4454-b101-153aec7bf835" />
<br>
<br>
<br>

29. With this, the hardware design is ready, and now it's time for the software part.
<br>
<br>
<br>

30. Now on the top pane, click on *Tools* and then select the *Launch Vitis IDE* option. Or you can also manually start the Vitis IDE.
<br>
<br>
<br>

31. The Vitis Launcher will prompt you to choose a workspace location, do it as per your convenience although keep it short and click on *Launch*
<img width="655" height="302" alt="image" src="https://github.com/user-attachments/assets/d2948ef4-a6b5-43f2-8418-f8b148ad56e3" />
<br>
<br>
<br>

32. Once the Vitis IDE launches, it will initiate some repos , it can be seen in the bottom right corner of the IDE. Let is complete and then click on *Create Platform Project*
<img width="1920" height="1046" alt="image" src="https://github.com/user-attachments/assets/e83a8e7b-74dc-4ff9-b1cb-8d56cdea22a9" />
<br>
<br>
<br>

33. Give the platform a name such as *hello_world_platform* and click *Next*
<img width="996" height="834" alt="image" src="https://github.com/user-attachments/assets/0b18c1e4-4351-45bb-92c4-89382a6fced0" />
<br>
<br>
<br>

34. Now select the .xsa hardware specification file, it is the one which we exported as hardware earlier from the Vivado GUI. Browse and select from where you exported it.
<img width="686" height="482" alt="image" src="https://github.com/user-attachments/assets/6d4e7479-f2fb-42f9-b8f4-e936bad7a9c6" />
<br>
<br>
<br>

35. Once selected, it will show up in the list, make sure it is selected and then click on *Finish*
<img width="991" height="828" alt="image" src="https://github.com/user-attachments/assets/098285f4-5c23-454e-8625-873e7e35af05" />
<br>
<br>
<br>

36. Now the platform that we created will be visible in the workspace on the left.
<img width="548" height="795" alt="image" src="https://github.com/user-attachments/assets/d03923e0-57b3-4568-92af-66d2f18399f9" />
<br>
<br>
<br>

37. Now click the hammer button i.e. the *Build* button to build the platform. You might be able to see the tiny exclamation mark beside the platform which indicates the platform isn't ready yet and hence the building required.
<img width="504" height="670" alt="image" src="https://github.com/user-attachments/assets/25c8eecb-172b-453b-9de6-a707d09b9bf3" />
<br>
<br>
<br>

38. Once the platform building is successful without errors, you should see the green tick beside the platform name as well as the build finished messagein the vitis console.
<img width="917" height="1006" alt="image" src="https://github.com/user-attachments/assets/f0364ac1-a641-4412-a7fc-ac46714a576b" />
<br>
<br>
<br>

39. Now in the explorer tab, select the platform by left clicking it and then click *New* and then select the *Application Project* , this pop-up will appear, click on *Next*
<img width="997" height="780" alt="image" src="https://github.com/user-attachments/assets/089bf34c-1c50-47c0-87de-548a8474861c" />
<br>
<br>
<br>

40. In the repository window, from the list of options, choose the platform we created earlier and click on *Next*
<img width="1000" height="784" alt="image" src="https://github.com/user-attachments/assets/30bbf862-33a8-40af-82ed-167deb2cb42a" />
<br>
<br>
<br>

41. In the project details window, give the project a name and select the processor by left clicking it and then click on *Next*
<img width="991" height="782" alt="image" src="https://github.com/user-attachments/assets/5ca9fa94-2580-4690-88ac-e9acbd71ab37" />
<br>
<br>
<br>

42. Select the domain as shown and click on *Next*
<img width="1000" height="782" alt="image" src="https://github.com/user-attachments/assets/7af95398-efaa-443a-ba24-9f4bfd744b4f" />
<br>
<br>
<br>

43. Now from the list of templates, select the *Hello World* template and then click on *Finish*
<img width="997" height="781" alt="image" src="https://github.com/user-attachments/assets/9cfb334c-a329-4a01-87aa-b5322ad1a840" />
<br>
<br>
<br>
