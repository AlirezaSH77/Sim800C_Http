/* USER CODE BEGIN PD */
 char mobileNumber[] = "+989910525255";  // Enter the Mobile Number you want to send to
 char ATcommand[200];
 uint8_t buffer[200] = {0};
 uint8_t ATisOK = 0;
 
 const char *plate = "ABC123";
 char jsonPayload[256];
 uint16_t payloadLength;

 char commandBuffer[100];

/* USER CODE END PD */

/*****************************/
/* USER CODE BEGIN 0 */

void sendData(const char *data) {
    HAL_UART_Transmit(&huart1, (uint8_t *)data, strlen(data), HAL_MAX_DELAY);
}

void sendATCommand(const char *command) {
    HAL_UART_Transmit(&huart1, (uint8_t *)command, strlen(command), HAL_MAX_DELAY);
}
/* USER CODE END 0 */
/*******************************
 while (1)
  {

		
			while(!ATisOK){
    		sprintf(ATcommand,"AT\r\n");
    		HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    		HAL_UART_Receive (&huart1, buffer, 200, 100);
    		HAL_Delay(1000);
    		if(strstr((char *)buffer,"OK")){
    			ATisOK = 1;
    		}
    		HAL_Delay(1000);
    		memset(buffer,0,sizeof(buffer));
 }
/**************************************/
    sprintf(ATcommand,"AT+CSQ\r\n");
    HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    HAL_UART_Receive (&huart1, buffer, 200, 100);
    HAL_Delay(4000);
    memset(buffer,0,sizeof(buffer));
 /*************************************/
 
    sprintf(ATcommand,"AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"\r\n");
    HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
    //HAL_Delay(3000);
    HAL_UART_Receive (&huart1, buffer, 200, 5000);
    HAL_Delay(2000);
    memset(buffer,0,sizeof(buffer));
 /**************************************/
 
 sprintf(ATcommand,"AT+SAPBR=3,1,\"YOUR_APN\",\"APN_NAME\"\r\n");
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"OK")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /*************************************/
 
 sprintf(ATcommand,"AT+SAPBR=1,1\r\n");                                      
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /************************************/
 
 sprintf(ATcommand,"AT+SAPBR=2,1\r\n");                                        //GET YOUR IP
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /***********************************/
 
 sprintf(ATcommand,"AT+HTTPINIT\r\n");                                            //INITIALIZE HTTP PROTOCOL
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /**********************************/
 
 sprintf(ATcommand,"AT+HTTPPARA=\"CID\",1\r\n");                                    // CONFIG CID
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(4000);
 memset(buffer,0,sizeof(buffer));
 /*********************************/
 
 sprintf(ATcommand,"AT+HTTPPARA=\"URL\",\"http://WWW.EXAMPLE.COM/END POINT\"\r\n");  //YOUR URL 
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /*********************************/
 
 sprintf(ATcommand,"AT+HTTPPARA=\"CONTENT\",\"application/json\"\r\n");                  //FORMAT OF SENDING DATA SUCH AS JSON AND ....
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 /*********************************/    
    // Create and send AT command with payload length
    char atCommand[50];
		snprintf(jsonPayload, sizeof(jsonPayload), "{YOUR JSON PAY LOAD);
		payloadLength = strlen(jsonPayload);                                                  // LENGTH OF JSON FILE

    snprintf(atCommand, sizeof(atCommand), "AT+HTTPDATA=%d,5000\r\n", payloadLength);    //SEND REQUEST FOR JSON FILE
    sendATCommand(atCommand);                                                            
    HAL_UART_Receive (&huart1, buffer, 200, 3000);
    // Send the JSON payload
    sendData(jsonPayload);                                                                //SEND JSON FILE
    HAL_UART_Receive (&huart1, buffer, 200, 3000);
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
 memset(buffer,0,sizeof(buffer));

 /*********************************/
 
 sprintf(ATcommand,"AT+HTTPACTION=1\r\n");                                                // SEND FILES TO SERVER BY POST METHOD
 HAL_UART_Transmit(&huart1,(uint8_t *)ATcommand,strlen(ATcommand),1000);
 HAL_UART_Receive (&huart1, buffer, 200, 3000);
 //if(strstr((char *)buffer,"")){
 //ATisOK = 1;
 //}
 HAL_Delay(3000);
 memset(buffer,0,sizeof(buffer));
