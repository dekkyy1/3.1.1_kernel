#include <linux/ioctl.h> /* for defining the IO controls */

/*****************************************************************************/
/* IO CONTROL definition for AIC3008                                         */
/*****************************************************************************/
#define AIC3008_IO_IOCTL_MAGIC		's'
#define AIC3008_IO_SET_TX_PARAM		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x10, unsigned)
#define AIC3008_IO_SET_RX_PARAM		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x11, unsigned)
#define AIC3008_IO_SET_DSP_PARAM	_IOW(AIC3008_IO_IOCTL_MAGIC, 0x12, unsigned)
#define AIC3008_IO_SET_DSP_INDEX	_IOW(AIC3008_IO_IOCTL_MAGIC, 0x13, unsigned)
#define AIC3008_IO_CONFIG_TX		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x14, unsigned int)
#define AIC3008_IO_CONFIG_RX		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x15, unsigned int)
#define AIC3008_IO_CONFIG_MEDIA		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x16, unsigned int)
#define AIC3008_IO_CONFIG_VOICE		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x22, unsigned int)
#define AIC3008_IO_CONFIG_VOLUME_L	_IOW(AIC3008_IO_IOCTL_MAGIC, 0x23, unsigned int)
#define AIC3008_IO_CONFIG_VOLUME_R	_IOW(AIC3008_IO_IOCTL_MAGIC, 0x24, unsigned int)
#define AIC3008_IO_POWERDOWN		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x25, unsigned int)
#define AIC3008_IO_LOOPBACK			_IOW(AIC3008_IO_IOCTL_MAGIC, 0x26, unsigned int)
#define AIC3008_IO_DUMP_PAGES		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x30, unsigned int)
#define AIC3008_IO_READ_REG			_IOWR(AIC3008_IO_IOCTL_MAGIC, 0x31, unsigned)
#define AIC3008_IO_WRITE_REG		_IOW(AIC3008_IO_IOCTL_MAGIC, 0x32, unsigned)
#define AIC3008_IO_RESET			_IOW(AIC3008_IO_IOCTL_MAGIC, 0x33, unsigned int)
#define AIC3008_IO_DUMP_DSP			_IOW(AIC3008_IO_IOCTL_MAGIC, 0x34, unsigned int)
#define AIC3008_IO_GET_PCBID		_IOR(AIC3008_IO_IOCTL_MAGIC, 0x35, unsigned int)

#define IO_CTL_ROW_MAX      64
#define IO_CTL_COL_MAX      1024
#define MINIDSP_ROW_MAX     40
#define MINIDSP_COL_MAX     20000

#define UPLINK_MODE_MAX		IO_CTL_ROW_MAX
#define DOWNLINK_MODE_MAX	IO_CTL_ROW_MAX
#define DSP_MODE_MAX		MINIDSP_ROW_MAX
#define AIC3008_PARA_MAX	IO_CTL_COL_MAX

/* structures for SPI commands */
typedef struct _CODEC_SPI_CMD {
	unsigned char act;
	unsigned char reg;
	unsigned char data;
} CODEC_SPI_CMD;

typedef struct _CODEC_SPI_CMD_PARAM {
	CODEC_SPI_CMD *data;
	unsigned int len;
} CODEC_SPI_CMD_PARAM;

struct AIC3008_PARAM {
	unsigned int row_num;
	unsigned int col_num;
	void *cmd_data;
};

/* enumerated modes */
enum aic3008_uplink_mode {
	INITIAL = 0,
	CALL_UPLINK_IMIC_RECEIVER = 1,
	CALL_UPLINK_EMIC_HEADPHONE = 2,
	CALL_UPLINK_IMIC_HEADPHONE = 3,
	CALL_UPLINK_IMIC_SPEAKER = 4,
	CALL_UPLINK_IMIC_RECEIVER_DUALMIC = 5,
	CALL_UPLINK_EMIC_HEADPHONE_DUALMIC = 6,
	CALL_UPLINK_IMIC_SPEAKER_DUALMIC = 7,
	VOICERECORD_IMIC = 8,
	VOICERECORD_EMIC = 9,
	VIDEORECORD_IMIC = 10,
	VIDEORECORD_EMIC = 11,
	VOICERECOGNITION_IMIC = 12,
	VOICERECOGNITION_EMIC = 13,
	UPLINK_BT_AP = 14,
	UPLINK_BT_BB = 15,
	FM_IN_SPEAKER = 16,
	FM_IN_HEADPHONE = 17,
	TTY_IN_HCO = 18,
	TTY_IN_VCO = 19,
	TTY_IN_FULL = 20,
	UPLINK_MUSE = 21,
	UPLINK_HAC = 22,
	UPLINK_PATH_OFF = 23,
	UPLINK_WAKEUP = 24,
	POWER_OFF = 25,
	STEREO_VIDEO_RECORDING_IMIC_PORTRAIT = 26,
	STEREO_VIDEO_RECORDING_IMIC_LANDSCAPE = 27,
	VOIP_UPLINK_IMIC_RECEIVER = 28,
	VOIP_UPLINK_EMIC_HEADPHONE = 29,
	VOIP_UPLINK_IMIC_HEADPHONE = 30,
	VOIP_UPLINK_IMIC_SPEAKER = 31,
	VOIP_UPLINK_BT = 32,
	CALL_UPLINK_IMIC_RECEIVER_DUALMIC_WB = 33,
	CALL_UPLINK_EMIC_HEADPHONE_DUALMIC_WB = 34,
	CALL_UPLINK_IMIC_SPEAKER_DUALMIC_WB = 35,
	CALL_UPLINK_IMIC_DOCK = 36,
	MFG_VIDEORECORD_2ndMIC = 37,
	CALL_UPLINK_EMIC_HEADPHONE_BEATS = 38,
	CALL_UPLINK_EMIC_HEADPHONE_BEATS_WB = 39,
	VOIP_UPLINK_EMIC_HEADPHONE_BEATS = 40,
	//CALL_DOWNLINK_IMIC_HEADPHONE_WB = 41, // conflicting declaration
	MFG_VOICERECORD_IMIC = 42,
	MFG_VOICERECORD_EMIC = 43,
	UPLINK_MODE_END = 44,
};

enum aic3008_downlink_mode {
	CALL_DOWNLINK_IMIC_RECEIVER = 1,
	CALL_DOWNLINK_EMIC_HEADPHONE = 2,
	CALL_DOWNLINK_IMIC_HEADPHONE = 3,
	CALL_DOWNLINK_IMIC_SPEAKER = 4,
	CALL_DOWNLINK_IMIC_RECEIVER_DUALMIC = 5,
	CALL_DOWNLINK_EMIC_HEADPHONE_DUALMIC = 6,
	CALL_DOWNLINK_IMIC_SPEAKER_DUALMIC = 7,
	PLAYBACK_RECEIVER = 8,
	PLAYBACK_HEADPHONE = 9,
	PLAYBACK_SPEAKER = 10,
	RING_HEADPHONE_SPEAKER = 11,
	PLAYBACK_SPEAKER_ALT = 12,
	USB_AUDIO = 13,
	DOWNLINK_BT_AP = 14,
	DOWNLINK_BT_BB = 15,
	FM_OUT_SPEAKER = 16,
	FM_OUT_HEADPHONE = 17,
	TTY_OUT_HCO = 18,
	TTY_OUT_VCO = 19,
	TTY_OUT_FULL = 20,
	DOWNLINK_MUSE = 21,
	DOWNLINK_HAC = 22,
	DOWNLINK_PATH_OFF = 23,
	DOWNLINK_WAKEUP = 24,
	PLAYBACK_HEADPHONE_URBEATS = 25,
	PLAYBACK_HEADPHONE_SOLO = 26,
	PLAYBACK_SPEAKER_BEATS = 27,
	VOIP_DOWNLINK_IMIC_RECEIVER = 28,
	VOIP_DOWNLINK_EMIC_HEADPHONE = 29,
	VOIP_DOWNLINK_IMIC_HEADPHONE = 30,
	VOIP_DOWNLINK_IMIC_SPEAKER = 31,
	VOIP_DOWNLINK_BT = 32,
	CALL_DOWNLINK_IMIC_RECEIVER_DUALMIC_WB = 33,
	CALL_DOWNLINK_EMIC_HEADPHONE_DUALMIC_WB = 34,
	CALL_DOWNLINK_IMIC_SPEAKER_DUALMIC_WB = 35,
	CALL_DOWNLINK_IMIC_DOCK = 36,
	PLAYBACK_DOCK = 37,
	CALL_DOWNLINK_EMIC_HEADPHONE_BEATS = 38,
	CALL_DOWNLINK_EMIC_HEADPHONE_BEATS_WB = 39,
	VOIP_DOWNLINK_EMIC_HEADPHONE_BEATS = 40,
	CALL_DOWNLINK_IMIC_HEADPHONE_WB = 41,
	MFG_PLAYBACK_L_SPEAKER = 42,
	MFG_PLAYBACK_R_SPEAKER = 43,
	PLAYBACK_HEADPHONE_FULLDELPX = 44,
	PLAYBACK_SPK_FULLDELPX = 45,
	MFG_PLAYBACK_RECEIVER = 46,
	DOWNLINK_MODE_END = 47,
};

enum htc_audio_sound_effect {
    MFG = 0,
	Phone_Default = 1,
	Phone_Receiver_Dualmic = 2,
	Phone_Speaker_Dualmic = 3,
	Phone_Headset = 4,
	Phone_HAC = 5,
	Phone_TTY = 6,
	Phone_BT = 7,
	Phone_Handset_Dualmic_WB = 8,
	Phone_Speaker_Dualmic_WB = 9,
	Phone_Headset_WB = 10,
	Phone_Dock = 11,
	Playback_Default = 12,
	Playback_Speaker_Default = 13,
	Playback_Headset_Generic = 14,
	Playback_Headset_urBeats = 15,
	Playback_Headset_Solo = 16,
	Playback_Headset_Pro = 17,
	Playback_Headset_Studio = 18,
	Playback_SPK_Beats = 19,
	Playback_Dock = 20,
	Playback_SPK_Ring = 21,
	Record_Default = 22,
	Record_V_Mono = 23,
	Record_V_IMIC_Landscape_Stereo = 24,
	Record_V_IMIC_Portrait_Stereo = 25,
	Record_A_VoiceRecoder_AMR = 26,
	Record_A_VoiceRecoder_AAC = 27,
	Record_A_Note_Recording = 28,
	Record_A_Speaker_VR = 29,
	FM_Headset = 30,
	FM_Speaker = 31,
	VOIP_Receiver = 32,
	VOIP_Speaker = 33,
	VOIP_Headset = 34,
	VOIP_BT = 35,
	VOIP_Receiver_HW_AEC = 36,
	VOIP_Speaker_HW_AEC = 37,
	VOIP_Headset_HW_AEC = 38,
	VOIP_BT_HW_AEC = 39,
	SKYPE_Receiver = 40,
	SKYPE_Speaker = 41,
	SPYPE_Headset = 42,
    End_Audio_Effect = 43,
};