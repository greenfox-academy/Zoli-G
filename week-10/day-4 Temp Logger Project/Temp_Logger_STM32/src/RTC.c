#include "main.h"

extern RTC_HandleTypeDef RtcHandle;

void RTC_Config(void) {
    RtcHandle.Instance = RTC;
    RtcHandle.Init.HourFormat = RTC_HOURFORMAT_24;
    RtcHandle.Init.AsynchPrediv = 124;                  // 124 for 1 second
    RtcHandle.Init.SynchPrediv = 255;                   // 255 for 1 second
    RtcHandle.Init.OutPut = RTC_OUTPUT_DISABLE;
    RtcHandle.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
    RtcHandle.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
    HAL_RTC_Init(&RtcHandle);
}

void RTC_SetDateTime(uint8_t year, uint8_t month, uint8_t day, uint8_t weekday,
    uint8_t hour, uint8_t minute, uint8_t second) {
    RTC_DateTypeDef sDate;
    RTC_TimeTypeDef sTime;

    sDate.Year = year;
    sDate.Month = month;
    sDate.Date = day;
    sDate.WeekDay = weekday;
    HAL_RTC_SetDate(&RtcHandle, &sDate, RTC_FORMAT_BIN);

    sTime.Hours = hour;
    sTime.Minutes = minute;
    sTime.Seconds = second;
    sTime.TimeFormat = RTC_HOURFORMAT_24;
    sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
    sTime.StoreOperation = RTC_STOREOPERATION_RESET;
    HAL_RTC_SetTime(&RtcHandle, &sTime, RTC_FORMAT_BIN);
}

