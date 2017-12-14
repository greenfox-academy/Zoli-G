//TC47 Temperature sensor address
#define I2C_ADDRESS 0x48 //0b1001000

//Function prototypes
void GPIOInit();
void I2CInit();
void I2C1_EV_IRQHandler(I2C_HandleTypeDef*);
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef*);
