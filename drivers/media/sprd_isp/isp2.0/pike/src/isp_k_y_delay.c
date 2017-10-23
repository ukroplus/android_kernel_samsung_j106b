/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
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

#include <linux/uaccess.h>
#include <linux/sprd_mm.h>
#include <video/sprd_isp.h>
#include "isp_reg.h"

static int32_t isp_k_ydelay_block(struct isp_io_param *param)
{
	int32_t ret = 0;
	struct isp_dev_ydelay_info ydelay_info;

	ret = copy_from_user((void *)&ydelay_info, param->property_param, sizeof(ydelay_info));
	if (0 != ret) {
		printk("isp_k_ydelay_block: copy_from_user error, ret = 0x%x\n", (uint32_t)ret);
		return -1;
	}

	if (ydelay_info.bypass) {
		REG_OWR(ISP_YDELAY_PARAM, BIT_0);
	} else {
		REG_MWR(ISP_YDELAY_PARAM, BIT_0, 0);
	}

	return ret;
}

int32_t isp_k_cfg_ydelay(struct isp_io_param *param)
{
	int32_t ret = 0;

	if (!param) {
		printk("isp_k_cfg_ydelay: param is null error.\n");
		return -1;
	}

	if (NULL == param->property_param) {
		printk("isp_k_cfg_ydelay: property_param is null error.\n");
		return -1;
	}

	switch(param->property) {
	case ISP_PRO_YDELAY_BLOCK:
		ret = isp_k_ydelay_block(param);
		break;
	default:
		printk("isp_k_cfg_ydelay: fail cmd id:%d, not supported.\n", param->property);
		break;
	}

	return ret;
}
