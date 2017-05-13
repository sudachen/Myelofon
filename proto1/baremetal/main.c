#pragma uccm default(board)= pca10040
#pragma uccm let(HEAP_SIZE)= 0
#pragma uccm let(CFLAGS_OPT)= -g -O1
#pragma uccm let(NRF_LOG_LEVEL)= 3

#include <uccm/board.h>
#include <~sudachen/uc_hardfault/import.h>
#include <~sudachen/uc_jprint/import.h>
#include <~sudachen/uc_waitfor/import.h>
#include <~sudachen/uc_blehid/import.h>
#include <~sudachen/uc_button/import.h>

int main()
{
    setup_board();
    completePrint_always();

    PRINT("ON START");

    setup_blehid("SIMPLE HID DEVICE", "ALEXEY SUDACHEN", 0xfe01, 0xfe01,
                 BLEHID_AUTO_READVERTISE|(get_boardButton(0)?BLEHID_ERASE_BONDS:0),
                 3,
                 BLEHID_INPUT_REPORT(8),
                 BLEHID_OUTPUT_REPORT(8),
                 BLEHID_FEATURE_REPORT(8));

    static RtcEvent Pulse = RTC_REPEAT_EVENT(500);
    list_event(&Pulse.e);
    static RtcEvent Update = RTC_REPEAT_EVENT(2000);
    list_event(&Update.e);
    static ButtonEvent Rebound = LONG_PRESS_BUTTON_EVENT(0,3000);
    list_event(&Rebound.e);
    static ButtonEvent Reset = CLICK_BUTTON_EVENT(0,250);
    list_event(&Reset.e);

    PRINT("starting BLE advertising");
    start_blehidAdvertising();

    for ( Event *e; (e = wait_forEvent()); complete_event(e) )
    {
        if ( EVENT_IS_BLEHID_REPORT(e) )
        {            
            const BleHidReport *r = getIf_blehidReport(e);
            switch ( kindOf_blehidReport(r) )
            {
                case BLEHID_OUTPUT_REPORT:
                    break;
                default:
                    ;
            }
        }
        else if ( EVENT_IS_BLEHID_CONNECT_CHANGED(e) )
        {
            PRINT("blehid is %?",$s(is_blehidConnected()?"connected":"diconnected"));
            if ( is_blehidConnected() )
                setOn_boardLED(1);
            else
                setOff_boardLED(1);
        }
        else if ( e == &Pulse.e )
        {
            toggle_boardLED(0);
        }
        else if ( e == &Update.e && is_blehidConnected() )
        {
            if ( use_blehidInputReport(0) != NULL )
            {
                fill_blehidReport(0xaa);
                send_blehidReport();
            }
            else
                PRINT("BLEHID input reports queue is full");
        }
        else if ( e == &Rebound.e || e == &Reset.e )
        {
            reset_board();
        }
    }
}
