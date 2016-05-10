/*! Symmetry Station \version 0.2.0
 *
 * \file      MIDI.h
 * \author    Chal J. McCollough
 * \copyright © 2012 Blue Storm Engineering. ®
 */


#ifndef __Win__MIDI__dot_h__
#define __Win__MIDI__dot_h__

#include <WinDef.h>

namespace SymmetryLiveAPI
{
    namespace Win
    {
        namespace MIDI
        {
/*
    Note: This seciton is here for referance only. These structs in in the Win.h header.
          This code is not a part of Symmetry Station and belongs to Microsoft.
*/


typedef struct MIDIEVENT_struct
{
    DWORD dwDeltaTime;  //!< Time (in MIDI ticks) between the previous event and the current event.
    DWORD dwStreamID;   //!< Reserved
                        /*!< Must be zero. */
    DWORD dwEvent;      //!< Event code and event parameters or length.
                        /*!< To parse this information, use the MEVT_EVENTTYPE and MEVT_EVENTPARM macros. */

    DWORD dwParms[];    //!< Event parameters.
                        /*!< If dwEvent specifies MEVT_F_LONG and the length of the buffer, this member contains
                             parameters for the event. This parameter data must be padded with zeros so that an
                             integral number of DWORD values are stored. For example, if the event data is five
                             bytes long, three pad bytes must follow the data for a total of eight bytes. In this
                             case, the low 24 bits of dwEvent would contain the value 5. If dwEvent specifies
                             MEVT_F_SHORT, do not use this member in the stream buffer. */
} MIDIEVENT;



typedef struct midihdr_tag
{
    LPSTR              lpData;          //!< Pointer to MIDI data.
    DWORD              dwBufferLength;  //!< Size of the buffer.
    DWORD              dwBytesRecorded; //!< Actual amount of data in the buffer.
                                        /*!< This value should be less than or equal to the value given in the
                                             dwBufferLength member. */
    DWORD_PTR          dwUser;          //!< Custom user data.
    DWORD              dwFlags;         //!< Flags giving information about the buffer.
    struct midihdr_tag  *lpNext;        //!< Reserved
                                        /*!< Do not use. */
    DWORD_PTR          reserved;        //!< Reserved
                                        /*!< Do not use. */
    DWORD              dwOffset;        //!< Offset into the buffer when a callback is performed.
                                        /*!< This callback is generated because the MEVT_F_CALLBACK flag is set
                                             in the dwEvent member of the MIDIEVENT structure. This offset
                                             enables an application to determine which event caused the callback. */
    DWORD_PTR          dwReserved[4];   //!< Reserved
                                        /*!< Do not use. */
} MIDIHDR, *LPMIDIHDR;




typedef struct
{
    WORD      wMid;              //!< Manufacturer identifier.
    WORD      wPid;              //!< Product identifier.
    MMVERSION vDriverVersion;    //!< Version number of the device driver for the MIDI input device.
                                 /*!< MSB = { version number }, LSB = { minor version number } */
    TCHAR  szPname[MAXPNAMELEN]; //!< Product name string.
                                 /*!< \pre szPname must be a null-terminated string. */
    DWORD     dwSupport;         //!< Reserved
                                 /*!< Must be zero */
} MIDIINCAPS;




typedef unsigned int MMVERSION;
typedef short TCHAR;

typedef struct
{
    WORD      wMid;                 //!< Manufacturer identifier of the device driver for the MIDI output device.
                                    /*!< Manufacturer identifiers are defined in Manufacturer and Product Identifiers. */
    WORD      wPid;                 //!< Product identifier of the MIDI output device.
                                    /*!< Product identifiers are defined in Manufacturer and Product Identifiers. */
    MMVERSION vDriverVersion;       //!< Version number of the device driver for the MIDI output device.
                                    /*!< The high-order byte is the major version number, and the low-order byte is
                                         the minor version number. */

    TCHAR     szPname[MAXPNAMELEN]; //!< Product name in a null-terminated string.
    WORD      wTechnology;          //!< Type of the MIDI output device.
    WORD      wVoices;              //!< Number of voices supported by an internal synthesizer device.
                                    /*!< If the device is a port, this member is not meaningful and is set to 0. */
    WORD      wNotes;               //!< Maximum number of simultaneous notes that can be played by an internal synthesizer device.
                                    /*!< If the device is a port, this member is not meaningful and is set to 0. */
    WORD      wChannelMask;         //!< Channels that an internal synthesizer device responds to.
                                    /*!< The least significant bit refers to channel 0 and the most significant bit to
                                         channel 15. Port devices that transmit on all channels set this member to 0xFFFF. */
    DWORD     dwSupport;            //!< Optional functionality supported by the device.
}   MIDIOUTCAPS;



typedef struct
{
    DWORD cbStruct;  //!< Length, in bytes, of this structure.
                     /*!< This member must be filled in for both the MIDIPROP_SET and MIDIPROP_GET operations of
                          the midiStreamProperty function. */
    DWORD dwTempo;   //!< Tempo of the stream, in microseconds per quarter note.
                     /*!< The tempo is honored only if the time division for the stream is specified in quarter
                          note format. This member is set in a MIDIPROP_SET operation and is filled on return
                          from a MIDIPROP_GET operation. */
} MIDIPROPTEMPO;



typedef struct
{
    DWORD cbStruct;   //!< Length, in bytes, of this structure.
                       /*!< This member must be filled in for both the MIDIPROP_SET and MIDIPROP_GET operations
                            of the midiStreamProperty function. */
    DWORD dwTimeDiv;  //!< Time division for this stream.
                       /*!< Format specified in the Standard MIDI Files 1.0 specification. The low 16 bits of this
                            DWORD value contain the time division. This member is set in a MIDIPROP_SET operation
                            and is filled on return from a MIDIPROP_GET operation. */
} MIDIPROPTIMEDIV;



typedef struct
{
    DWORD dwVersion;    //!< Version of the stream.
                         /*!< The high 16 bits contain the major version, and the low 16 bits contain the minor
                              version. The version number for the first implementation of MIDI streams should be 1.0. */

    DWORD dwMid;        //!< Manufacturer identifier.
                         /*!< Manufacturer identifiers are defined in Manufacturer and Product Identifiers. */

    DWORD dwOEMVersion; //!< OEM version of the stream.
                         /*!< Original equipment manufacturers can use this field to version-stamp any custom events
                              they have specified. If a custom event is specified, it must be the first event sent
                              after the stream is opened. */
} MIDISTRMBUFFVER;


enum MMRESULT
{
  MMSYSERR_NOERROR        = 0,
  MMSYSERR_ERROR          = 1,
  MMSYSERR_BADDEVICEID    = 2,
  MMSYSERR_NOTENABLED     = 3,
  MMSYSERR_ALLOCATED      = 4,
  MMSYSERR_INVALHANDLE    = 5,
  MMSYSERR_NODRIVER       = 6,
  MMSYSERR_NOMEM          = 7,
  MMSYSERR_NOTSUPPORTED   = 8,
  MMSYSERR_BADERRNUM      = 9,
  MMSYSERR_INVALFLAG      = 10,
  MMSYSERR_INVALPARAM     = 11,
  MMSYSERR_HANDLEBUSY     = 12,
  MMSYSERR_INVALIDALIAS   = 13,
  MMSYSERR_BADDB          = 14,
  MMSYSERR_KEYNOTFOUND    = 15,
  MMSYSERR_READERROR      = 16,
  MMSYSERR_WRITEERROR     = 17,
  MMSYSERR_DELETEERROR    = 18,
  MMSYSERR_VALNOTFOUND    = 19,
  MMSYSERR_NODRIVERCB     = 20,
  WAVERR_BADFORMAT        = 32,
  WAVERR_STILLPLAYING     = 33,
  WAVERR_UNPREPARED       = 34
};



/*

    Common Return codes

    MMSYSERR_NOERROR (0)
        The function completed normally.

    MMSYSERR_BADDEVICEID (2)
        An out-of-range device ID was specified.

    MMSYSERR_ALLOCATED (4)
        Device is already allocated and is not available.

    MMSYSERR_INVALHANDLE (5)
        An illegal device handle was specified.

    MMSYSERR_NODRIVER (6)
        No device driver is present for this device.

    MMSYSERR_NOMEM (7)
        Driver memory allocation error.

    MIDIERR_UNPREPARED (64)
        Header is not prepared.

    MIDIERR_STILLPLAYING (65)
        Attempt to close device while still playing.

    MIDIERR_NOTREADY (67)
        Hardware is busy.

MIDI Input Functions

    UINT midiInGetNumDevs();
        Returns the number of input devices available on the system.

    UINT midiInGetDevCaps(UINT wDeviceID, LPMIDIINCAPS lpCaps, UINT wSize);
        Fills the MIDIINCAPS structure, pointed to by lpCaps, with the capabilities for the specified device.

    UINT midiInOpen(LPHMIDIIN lphMidiIn, UINT wDeviceID, DWORD dwCallback, DWORD dwCallbackInstance, DWORD dwFlags);
        Opens the specified device for input. A handle to the device is returned in lphMidiIn. dwFlags specifies the type of callback that is used to alert the application to events. Common callback types are CALLBACK_WINDOW and CALLBACK_FUNCTION. dwCallback specifies the callback function address or window handle, while dwCallbackInstance specifies user data that are passed to callback functions (but not to window callbacks).

    UINT midiInClose(HMIDIIN hMidiIn);
        Closes the specified input device.

    UINT midiInPrepareHeader(HMIDIIN hMidiIn, LPMIDIHDR lpMidiInHdr, UINT wSize);
        Prepares a header, normally used for sysex messages, for processing by the device. The header structure and data buffer (lpData field of MIDIHDR structure) must be allocated using GlobalAlloc() using the GMEM_MOVEABLE and GMEM_SHARE flags.

    UINT midiInUnprepareHeader(HMIDIIN hMidiIn, LPMIDIHDR lpMidiInHdr, UINT wSize);
        Cleans up the preparation done by a previous call to midiInPrepareHeader().

    UINT midiInAddBuffer(HMIDIIN hMidiIn, LPMIDIHDR lpMidiInHdr, UINT wSize);
        Sends the buffer managed by the specified MIDIHDR structure to the device. Received sysex data are stored in the buffer which is returned to the application when filled.

    UINT midiInStart(HMIDIIN hMidiIn);
        Enables MIDI input from the already-opened device.

    UINT midiInStop(HMIDIIN hMidiIn);
        Stops MIDI input from the device.

    UINT midiInReset(HMIDIIN hMidiIn);
        Flushes any pending input buffers and stops input.


MIDI Output Functions

    UINT midiOutGetNumDevs();
        Returns the number of output devices available on the system.

    UINT midiOutGetDevCaps(UINT wDeviceID, LPMIDIOUTCAPS lpCaps, UINT wSize);
        Fills the MIDIOUTCAPS structure, pointed to by lpCaps, with the capabilities for the specified device.

    UINT midiOutOpen(LPHMIDIOUT lphMidiOut, UINT wDeviceID, DWORD dwCallback, DWORD dwCallbackInstance, DWORD dwFlags);
        Opens the specified device for output. A handle to the device is returned in lphMidiOut. dwFlags specifies the type of callback that is used to alert the application. Common callback types are CALLBACK_WINDOW and CALLBACK_FUNCTION. dwCallback specifies the callback function address or window handle, while dwCallbackInstance specifies user data that are passed to callback functions (but not to window callbacks).

    UINT midiOutClose(HMIDIOUT hMidiOut);
        Closes the specified output device.

    UINT midiOutShortMsg(HMIDIOUT hMidiOut, DWORD dwMsg);
        Sends a short (non-sysex) message to the specified device. The message is packed into a DWORD, with the first byte of the message in the least significant byte.

    UINT midiOutLongMsg(HMIDIOUT hMidiOut, LPMIDIHDR lpMidiOutHdr, UINT wSize);
        Sends a buffer of data, generally part or all of a sysex, to the specified device. The MIDIHDR structure must be properly initialized and prepared before calling this function.

    UINT midiOutPrepareHeader(HMIDIOUT hMidiOut, LPMIDIHDR lpMidiOutHdr, UINT wSize);
        Prepares a header, normally used for sysex messages, for processing by the device. The header structure and data buffer (lpData field of MIDIHDR structure) must be allocated using GlobalAlloc() using the GMEM_MOVEABLE and GMEM_SHARE flags.

    UINT midiOutUnprepareHeader(HMIDIOUT hMidiOut, LPMIDIHDR lpMidiOutHdr, UINT wSize);
        Cleans up the preparation done by a previous call to midiOutPrepareHeader().

    UINT midiOutReset(HMIDIOUT hMidiOut);
        Flushes any pending output buffers and, with some drivers, also sends Note Off messages for all notes on all channels.
 */
        }
    }
}

#endif // End __Win__MIDI__h__
