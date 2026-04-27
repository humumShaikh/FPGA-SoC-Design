# FPGA SoC Design to control the PSPI MASTER AND SLAVE Modules
<br>
<br>
<br>
<br>
<br>

***PSPI MASTER Controller***
<img width="1271" height="792" alt="image" src="https://github.com/user-attachments/assets/8326e09c-be77-463b-be8a-5ce29c202f00" />
<br>
<br>
The basic idea is to use the PSPI Master as an IP block and connect it's IO ports with the ZYNQ Processing system to stimulate and control the master.
The ZYNQ Processing system will give input, read output to the PSPI master implemented in the ZYNQ Programmable Logic (FPGA) part of the SoC.
Simply put, if there was a scarcity of Switches and buttons on the development board, then this would be one of the ways to test the design live physically.
