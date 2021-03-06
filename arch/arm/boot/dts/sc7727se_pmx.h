/*
 * Copyright (C) 2015 Samsung Electronics Co, Ltd.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __SC7727SE_PMX_H__
#define __SC7727SE_PMX_H__

#ifdef SPRD_PINCTRL
#error "__SCYYXX_PMX_H__ file must be inclued once!"
#else
#define SPRD_PINCTRL
#endif

/* [21:18] PIN_NAME_drv : drive strength current, mask */
#define MASK_PIN_DS			(((1 << (21 - 18 + 1)) - 1) << 18)

#define PMX_PIN_DS(_ds)			pinctrl-single,drive-strength = <\
						((_ds) << 18) MASK_PIN_DS>

/* [11] PIN_NAME_se : input, enable bits, disable bits, mask */
#define BITS_PIN_HYS_DIS		0x0
#define BITS_PIN_HYS_EN			(0x1 << 11)
#define MASK_PIN_HYS			BITS_PIN_HYS_EN

#define PMX_PIN_HYS_DIS			pinctrl-single,input-schmitt = <\
						BITS_PIN_HYS_DIS	\
						MASK_PIN_HYS>
#define PMX_PIN_HYS_EN			pinctrl-single,input-schmitt = <\
						BITS_PIN_HYS_EN		\
						MASK_PIN_HYS>

/* [12,7,6] PIN_NAME_wpus, PIN_NAME_func_wpu, PIN_NAME_wpd */
#define BITS_PIN_FLOAT			0x0
#define BITS_PIN_WPUS			(0x1 << 12)	/* TODO: do NOT use alone */
#define BITS_PIN_WPU			(0x1 << 7)
#define BITS_PIN_WPU_WPUS		(BITS_PIN_WPU | BITS_PIN_WPUS)
#define BITS_PIN_WPD			(0x1 << 6)
#define ENABLE_WPU			BITS_PIN_WPU
#define DISABLE_WPU			0x0
#define ENABLE_WPU_WPUS			BITS_PIN_WPU_WPUS
#define DISABLE_WPU_WPUS		0x0
#define ENABLE_WPD			BITS_PIN_WPD
#define DISABLE_WPD			0x0
#define MASK_PIN_WPU			(BITS_PIN_WPU | BITS_PIN_WPUS)
#define MASK_PIN_WPD			(BITS_PIN_WPD)

#define PMX_PIN_FLOAT			pinctrl-single,bias-pullup = <	\
						BITS_PIN_FLOAT		\
						ENABLE_WPU		\
						DISABLE_WPU		\
						MASK_PIN_WPU>;		\
					pinctrl-single,bias-pulldown = <\
						BITS_PIN_FLOAT		\
						ENABLE_WPD		\
						BITS_PIN_FLOAT		\
						MASK_PIN_WPD>
#define PMX_PIN_WPU_20K			pinctrl-single,bias-pullup = <	\
						BITS_PIN_WPU		\
						ENABLE_WPU		\
						DISABLE_WPU		\
						MASK_PIN_WPU>;		\
					pinctrl-single,bias-pulldown = <\
						BITS_PIN_FLOAT		\
						ENABLE_WPD		\
						DISABLE_WPD		\
						MASK_PIN_WPD>
#define PMX_PIN_WPU_4K7			pinctrl-single,bias-pullup = <	\
						BITS_PIN_WPU_WPUS	\
						ENABLE_WPU_WPUS		\
						DISABLE_WPU_WPUS	\
						MASK_PIN_WPU>;		\
					pinctrl-single,bias-pulldown = <\
						BITS_PIN_FLOAT		\
						ENABLE_WPD		\
						DISABLE_WPD		\
						MASK_PIN_WPD>
#define PMX_PIN_WPD_50K			pinctrl-single,bias-pullup = <	\
						BITS_PIN_FLOAT		\
						ENABLE_WPU		\
						DISABLE_WPU		\
						MASK_PIN_WPU>;		\
					pinctrl-single,bias-pulldown = <\
						BITS_PIN_WPD		\
						ENABLE_WPD		\
						DISABLE_WPD		\
						MASK_PIN_WPD>

/* [3:0] PIN_NAME_slp_wpu, PIN_NAME_slp_wpd, PIN_NAME_slp_ie, PIN_NAME_slp_oe */
#define BITS_PIN_SLP_FLOAT		0x0
#define BITS_PIN_SLP_OUT		(0x1 << 0)
#define BITS_PIN_SLP_IN			(0x1 << 1)
#define BITS_PIN_SLP_WPD		(0x1 << 2)
#define BITS_PIN_SLP_WPU		(0x1 << 3)
#define BITS_PIN_SLP_OUT_WPU		(BITS_PIN_SLP_OUT | BITS_PIN_SLP_WPU)
#define BITS_PIN_SLP_OUT_WPD		(BITS_PIN_SLP_OUT | BITS_PIN_SLP_WPD)
#define BITS_PIN_SLP_IN_WPU		(BITS_PIN_SLP_IN | BITS_PIN_SLP_WPU)
#define BITS_PIN_SLP_IN_WPD		(BITS_PIN_SLP_IN | BITS_PIN_SLP_WPD)
#define MASK_PIN_SLP			(BITS_PIN_SLP_OUT | BITS_PIN_SLP_IN |\
					 BITS_PIN_SLP_WPD | BITS_PIN_SLP_WPU)

#define PMX_PIN_SLP_FLOAT		pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_FLOAT	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_OUT			pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_OUT	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_IN			pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_IN	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_WPD			pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_WPD	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_WPU			pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_WPU	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_OUT_WPU		pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_OUT_WPU	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_OUT_WPD		pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_OUT_WPD	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_IN_WPU		pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_IN_WPU	\
						MASK_PIN_SLP>
#define PMX_PIN_SLP_IN_WPD		pinctrl-single,low-power-mode = <\
						BITS_PIN_SLP_IN_WPD	\
						MASK_PIN_SLP>

/* [16:13] PIN_NAME_slp_en */
#define BITS_PIN_SLP_NONE		0x0
#define BITS_PIN_SLP_AP			(0x1 << 13)
#define BITS_PIN_SLP_CP0		(0x1 << 14)
#define BITS_PIN_SLP_CP1		(0x1 << 15)
#define BITS_PIN_SLP_CP2		(0x1 << 16)
#define BITS_PIN_SLP_DCP		(BITS_PIN_SLP_CP0 | BITS_PIN_SLP_CP1 |\
					 BITS_PIN_SLP_CP2)
#define BITS_PIN_SLP_ALL		(BITS_PIN_SLP_AP | BITS_PIN_SLP_DCP)
#define MASK_PIN_SLP_SRC			(BITS_PIN_SLP_ALL)

/* [5:4] PIN_NAME_sel */
#define BITS_PIN_AF(_af)		((_af) << 4)
#define MASK_PIN_AF			(0x3 << 4)

/* Pin Control Register Offsets */
#define PIN_REG_PIN_CTRL_REG0		0x0000
#define PIN_REG_PIN_CTRL_REG1		0x0004
#define PIN_REG_PIN_CTRL_REG2		0x0008
#define PIN_REG_PIN_CTRL_REG3		0x000C
#define PIN_REG_PIN_CTRL_REG4		0x0010
#define PIN_REG_PIN_CTRL_REG5		0x0014
#define PIN_REG_PIN_CTRL_REG6		0x0018
#define PIN_REG_PIN_CTRL_REG7		0x001C

/* Other Pin Control Register Offsets */
#define OTHER_PIN_REG_OFFSET		0x0020
#define PIN_REG_RFSDA0			(0x0020 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFSCK0			(0x0024 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFSEN0			(0x0028 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL0			(0x002C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL1			(0x0030 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL2			(0x0034 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL3			(0x0038 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL4			(0x003C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL5			(0x0040 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL6			(0x0044 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL7			(0x0048 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL8			(0x004C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL9			(0x0050 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL10			(0x0054 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL11			(0x0058 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL12			(0x005C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL13			(0x0060 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL14			(0x0064 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RFCTL15			(0x0068 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_PTEST			(0x006C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_ANA_INT			(0x0070 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_EXT_RST_B		(0x0074 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CHIP_SLEEP		(0x0078 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_XTL_BUF_EN0		(0x007C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_XTL_BUF_EN1		(0x0080 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CLK_32K			(0x0084 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_SCLK		(0x0088 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_ADD0		(0x008C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_ADSYNC		(0x0090 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_DAD1		(0x0094 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_DAD0		(0x0098 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_AUD_DASYNC		(0x009C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_ADI_D			(0x00A0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_ADI_SYNC		(0x00A4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_ADI_SCLK		(0x00A8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_LCD_RSTN		(0x00AC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_LCD_FMARK		(0x00B0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SPI1_CSN		(0x00B4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SPI1_DO			(0x00B8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SPI1_DI			(0x00BC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SPI1_CLK		(0x00C0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFWPN			(0x00C4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFRBN			(0x00C8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFCLE			(0x00CC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFALE			(0x00D0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFREN			(0x00D4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD4			(0x00D8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD5			(0x00DC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD6			(0x00E0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD7			(0x00E4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD10			(0x00E8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD11			(0x00EC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD14			(0x00F0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFCEN0			(0x00F4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFCEN1			(0x00F8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFWEN			(0x00FC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD0			(0x0100 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD1			(0x0104 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD2			(0x0108 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD3			(0x010C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD8			(0x0110 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD9			(0x0114 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD12			(0x0118 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD13			(0x011C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_NFD15			(0x0120 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CCIRMCLK		(0x0124 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CCIRRST			(0x0128 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CCIRPD1			(0x012C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CCIRPD0			(0x0130 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SCL0			(0x0134 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SDA0			(0x0138 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYOUT0			(0x013C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYOUT1			(0x0140 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYOUT2			(0x0144 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYIN0			(0x0148 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYIN1			(0x014C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_KEYIN2			(0x0150 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CLK_AUX0		(0x0154 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CLK_AUX1		(0x0158 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_IIS0DI			(0x015C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_IIS0DO			(0x0160 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_IIS0CLK			(0x0164 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_IIS0LRCK		(0x0168 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_MTDO			(0x016C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_MTDI			(0x0170 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_MTCK			(0x0174 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_MTMS			(0x0178 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_MTRST_N			(0x017C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACECLK		(0x0180 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACECTRL		(0x0184 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT0		(0x0188 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT1		(0x018C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT2		(0x0190 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT3		(0x0194 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT4		(0x0198 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT5		(0x019C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT6		(0x01A0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_TRACEDAT7		(0x01A4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U0TXD			(0x01A8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U0RXD			(0x01AC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U0CTS			(0x01B0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U0RTS			(0x01B4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U1TXD			(0x01B8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U1RXD			(0x01BC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U2TXD			(0x01C0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U2RXD			(0x01C4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U2CTS			(0x01C8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_U2RTS			(0x01CC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SCL2			(0x01D0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SDA2			(0x01D4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_EXTINT0			(0x01D8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_EXTINT1			(0x01DC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SCL1			(0x01E0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SDA1			(0x01E4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMCLK0			(0x01E8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMDA0			(0x01EC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMRST0			(0x01F0 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMCLK1			(0x01F4 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMDA1			(0x01F8 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMRST1			(0x01FC - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMCLK2			(0x0200 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMDA2			(0x0204 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SIMRST2			(0x0208 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_CLK			(0x020C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_CMD			(0x0210 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_D0			(0x0214 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_D1			(0x0218 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_D2			(0x021C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD1_D3			(0x0220 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_D3			(0x0224 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_D2			(0x0228 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_CMD			(0x022C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_D0			(0x0230 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_D1			(0x0234 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_SD0_CLK0		(0x0238 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RF_ADC_ON		(0x023C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_RF_DAC_ON		(0x0240 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CP2_RFCTL0		(0x0338 - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CP2_RFCTL1		(0x033C - OTHER_PIN_REG_OFFSET)
#define PIN_REG_CP2_RFCTL2		(0x0340 - OTHER_PIN_REG_OFFSET)

#endif /* __SC7727SE_PMX_H__ */
