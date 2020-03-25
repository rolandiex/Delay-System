/*==========================================
* Keitenai Delay System [ keitenai ]
*------------------------------------------*/
int keitenai_sk_delay (struct map_session_data *sd, uint16 skill_id, uint16 skill_lv,int flag){

	char message_skdelay[200];
	int m, k = 1000, show_delay = battle_config.KEITENAI_SHOW_DELAY;
	struct map_data *mapdata = map_getmapdata(sd->bl.m);

	switch (skill_id) {
		case SM_BASH:
			if(DIFF_TICK(sd->K_CHK_SM_BASH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SM_BASH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SM_BASH >= (battle_config.WOE_K_DELAY_SM_BASH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SM_BASH >= (battle_config.K_DELAY_SM_BASH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SM_BASH = sd->K_LOCK_SM_BASH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SM_BASH = gettick() + battle_config.WOE_K_DELAY_SM_BASH;
				else
					sd->K_CHK_SM_BASH = gettick() + battle_config.K_DELAY_SM_BASH;

				sd->K_LOCK_SM_BASH = 0;
			}
			break;
		case SM_MAGNUM:
			if(DIFF_TICK(sd->K_CHK_SM_MAGNUM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SM_MAGNUM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SM_MAGNUM >= (battle_config.WOE_K_DELAY_SM_MAGNUM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SM_MAGNUM >= (battle_config.K_DELAY_SM_MAGNUM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SM_MAGNUM = sd->K_LOCK_SM_MAGNUM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SM_MAGNUM = gettick() + battle_config.WOE_K_DELAY_SM_MAGNUM;
				else
					sd->K_CHK_SM_MAGNUM = gettick() + battle_config.K_DELAY_SM_MAGNUM;

				sd->K_LOCK_SM_MAGNUM = 0;
			}
			break;
		case MG_NAPALMBEAT:
			if(DIFF_TICK(sd->K_CHK_MG_NAPALMBEAT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_NAPALMBEAT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_NAPALMBEAT >= (battle_config.WOE_K_DELAY_MG_NAPALMBEAT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_NAPALMBEAT >= (battle_config.K_DELAY_MG_NAPALMBEAT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_NAPALMBEAT = sd->K_LOCK_MG_NAPALMBEAT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_NAPALMBEAT = gettick() + battle_config.WOE_K_DELAY_MG_NAPALMBEAT;
				else
					sd->K_CHK_MG_NAPALMBEAT = gettick() + battle_config.K_DELAY_MG_NAPALMBEAT;

				sd->K_LOCK_MG_NAPALMBEAT = 0;
			}
			break;
		case MG_SOULSTRIKE:
			if(DIFF_TICK(sd->K_CHK_MG_SOULSTRIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_SOULSTRIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_SOULSTRIKE >= (battle_config.WOE_K_DELAY_MG_SOULSTRIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_SOULSTRIKE >= (battle_config.K_DELAY_MG_SOULSTRIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_SOULSTRIKE = sd->K_LOCK_MG_SOULSTRIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_SOULSTRIKE = gettick() + battle_config.WOE_K_DELAY_MG_SOULSTRIKE;
				else
					sd->K_CHK_MG_SOULSTRIKE = gettick() + battle_config.K_DELAY_MG_SOULSTRIKE;

				sd->K_LOCK_MG_SOULSTRIKE = 0;
			}
			break;
		case MG_COLDBOLT:
			if(DIFF_TICK(sd->K_CHK_MG_COLDBOLT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_COLDBOLT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_COLDBOLT >= (battle_config.WOE_K_DELAY_MG_COLDBOLT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_COLDBOLT >= (battle_config.K_DELAY_MG_COLDBOLT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_COLDBOLT = sd->K_LOCK_MG_COLDBOLT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_COLDBOLT = gettick() + battle_config.WOE_K_DELAY_MG_COLDBOLT;
				else
					sd->K_CHK_MG_COLDBOLT = gettick() + battle_config.K_DELAY_MG_COLDBOLT;

				sd->K_LOCK_MG_COLDBOLT = 0;
			}
			break;
		case MG_FROSTDIVER:
			if(DIFF_TICK(sd->K_CHK_MG_FROSTDIVER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_FROSTDIVER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_FROSTDIVER >= (battle_config.WOE_K_DELAY_MG_FROSTDIVER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_FROSTDIVER >= (battle_config.K_DELAY_MG_FROSTDIVER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_FROSTDIVER = sd->K_LOCK_MG_FROSTDIVER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_FROSTDIVER = gettick() + battle_config.WOE_K_DELAY_MG_FROSTDIVER;
				else
					sd->K_CHK_MG_FROSTDIVER = gettick() + battle_config.K_DELAY_MG_FROSTDIVER;

				sd->K_LOCK_MG_FROSTDIVER = 0;
			}
			break;
		case MG_STONECURSE:
			if(DIFF_TICK(sd->K_CHK_MG_STONECURSE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_STONECURSE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_STONECURSE >= (battle_config.WOE_K_DELAY_MG_STONECURSE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_STONECURSE >= (battle_config.K_DELAY_MG_STONECURSE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_STONECURSE = sd->K_LOCK_MG_STONECURSE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_STONECURSE = gettick() + battle_config.WOE_K_DELAY_MG_STONECURSE;
				else
					sd->K_CHK_MG_STONECURSE = gettick() + battle_config.K_DELAY_MG_STONECURSE;

				sd->K_LOCK_MG_STONECURSE = 0;
			}
			break;
		case MG_FIREBALL:
			if(DIFF_TICK(sd->K_CHK_MG_FIREBALL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_FIREBALL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_FIREBALL >= (battle_config.WOE_K_DELAY_MG_FIREBALL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_FIREBALL >= (battle_config.K_DELAY_MG_FIREBALL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_FIREBALL = sd->K_LOCK_MG_FIREBALL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_FIREBALL = gettick() + battle_config.WOE_K_DELAY_MG_FIREBALL;
				else
					sd->K_CHK_MG_FIREBALL = gettick() + battle_config.K_DELAY_MG_FIREBALL;

				sd->K_LOCK_MG_FIREBALL = 0;
			}
			break;
		case MG_FIREWALL:
			if(DIFF_TICK(sd->K_CHK_MG_FIREWALL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_FIREWALL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_FIREWALL >= (battle_config.WOE_K_DELAY_MG_FIREWALL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_FIREWALL >= (battle_config.K_DELAY_MG_FIREWALL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_FIREWALL = sd->K_LOCK_MG_FIREWALL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_FIREWALL = gettick() + battle_config.WOE_K_DELAY_MG_FIREWALL;
				else
					sd->K_CHK_MG_FIREWALL = gettick() + battle_config.K_DELAY_MG_FIREWALL;

				sd->K_LOCK_MG_FIREWALL = 0;
			}
			break;
		case MG_FIREBOLT:
			if(DIFF_TICK(sd->K_CHK_MG_FIREBOLT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_FIREBOLT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_FIREBOLT >= (battle_config.WOE_K_DELAY_MG_FIREBOLT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_FIREBOLT >= (battle_config.K_DELAY_MG_FIREBOLT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_FIREBOLT = sd->K_LOCK_MG_FIREBOLT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_FIREBOLT = gettick() + battle_config.WOE_K_DELAY_MG_FIREBOLT;
				else
					sd->K_CHK_MG_FIREBOLT = gettick() + battle_config.K_DELAY_MG_FIREBOLT;

				sd->K_LOCK_MG_FIREBOLT = 0;
			}
			break;
		case MG_LIGHTNINGBOLT:
			if(DIFF_TICK(sd->K_CHK_MG_LIGHTNINGBOLT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_LIGHTNINGBOLT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_LIGHTNINGBOLT >= (battle_config.WOE_K_DELAY_MG_LIGHTNINGBOLT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_LIGHTNINGBOLT >= (battle_config.K_DELAY_MG_LIGHTNINGBOLT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_LIGHTNINGBOLT = sd->K_LOCK_MG_LIGHTNINGBOLT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_LIGHTNINGBOLT = gettick() + battle_config.WOE_K_DELAY_MG_LIGHTNINGBOLT;
				else
					sd->K_CHK_MG_LIGHTNINGBOLT = gettick() + battle_config.K_DELAY_MG_LIGHTNINGBOLT;

				sd->K_LOCK_MG_LIGHTNINGBOLT = 0;
			}
			break;
		case MG_THUNDERSTORM:
			if(DIFF_TICK(sd->K_CHK_MG_THUNDERSTORM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MG_THUNDERSTORM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MG_THUNDERSTORM >= (battle_config.WOE_K_DELAY_MG_THUNDERSTORM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MG_THUNDERSTORM >= (battle_config.K_DELAY_MG_THUNDERSTORM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MG_THUNDERSTORM = sd->K_LOCK_MG_THUNDERSTORM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MG_THUNDERSTORM = gettick() + battle_config.WOE_K_DELAY_MG_THUNDERSTORM;
				else
					sd->K_CHK_MG_THUNDERSTORM = gettick() + battle_config.K_DELAY_MG_THUNDERSTORM;

				sd->K_LOCK_MG_THUNDERSTORM = 0;
			}
			break;
		case AL_HEAL:
			if(DIFF_TICK(sd->K_CHK_AL_HEAL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AL_HEAL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AL_HEAL >= (battle_config.WOE_K_DELAY_AL_HEAL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AL_HEAL >= (battle_config.K_DELAY_AL_HEAL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AL_HEAL = sd->K_LOCK_AL_HEAL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AL_HEAL = gettick() + battle_config.WOE_K_DELAY_AL_HEAL;
				else
					sd->K_CHK_AL_HEAL = gettick() + battle_config.K_DELAY_AL_HEAL;

				sd->K_LOCK_AL_HEAL = 0;
			}
			break;
		case AL_DECAGI:
			if(DIFF_TICK(sd->K_CHK_AL_DECAGI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AL_DECAGI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AL_DECAGI >= (battle_config.WOE_K_DELAY_AL_DECAGI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AL_DECAGI >= (battle_config.K_DELAY_AL_DECAGI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AL_DECAGI = sd->K_LOCK_AL_DECAGI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AL_DECAGI = gettick() + battle_config.WOE_K_DELAY_AL_DECAGI;
				else
					sd->K_CHK_AL_DECAGI = gettick() + battle_config.K_DELAY_AL_DECAGI;

				sd->K_LOCK_AL_DECAGI = 0;
			}
			break;
		case AL_CRUCIS:
			if(DIFF_TICK(sd->K_CHK_AL_CRUCIS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AL_CRUCIS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AL_CRUCIS >= (battle_config.WOE_K_DELAY_AL_CRUCIS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AL_CRUCIS >= (battle_config.K_DELAY_AL_CRUCIS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AL_CRUCIS = sd->K_LOCK_AL_CRUCIS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AL_CRUCIS = gettick() + battle_config.WOE_K_DELAY_AL_CRUCIS;
				else
					sd->K_CHK_AL_CRUCIS = gettick() + battle_config.K_DELAY_AL_CRUCIS;

				sd->K_LOCK_AL_CRUCIS = 0;
			}
			break;
		case MC_MAMMONITE:
			if(DIFF_TICK(sd->K_CHK_MC_MAMMONITE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MC_MAMMONITE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MC_MAMMONITE >= (battle_config.WOE_K_DELAY_MC_MAMMONITE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MC_MAMMONITE >= (battle_config.K_DELAY_MC_MAMMONITE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MC_MAMMONITE = sd->K_LOCK_MC_MAMMONITE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MC_MAMMONITE = gettick() + battle_config.WOE_K_DELAY_MC_MAMMONITE;
				else
					sd->K_CHK_MC_MAMMONITE = gettick() + battle_config.K_DELAY_MC_MAMMONITE;

				sd->K_LOCK_MC_MAMMONITE = 0;
			}
			break;
		case AC_DOUBLE:
			if(DIFF_TICK(sd->K_CHK_AC_DOUBLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AC_DOUBLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AC_DOUBLE >= (battle_config.WOE_K_DELAY_AC_DOUBLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AC_DOUBLE >= (battle_config.K_DELAY_AC_DOUBLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AC_DOUBLE = sd->K_LOCK_AC_DOUBLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AC_DOUBLE = gettick() + battle_config.WOE_K_DELAY_AC_DOUBLE;
				else
					sd->K_CHK_AC_DOUBLE = gettick() + battle_config.K_DELAY_AC_DOUBLE;

				sd->K_LOCK_AC_DOUBLE = 0;
			}
			break;
		case AC_SHOWER:
			if(DIFF_TICK(sd->K_CHK_AC_SHOWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AC_SHOWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AC_SHOWER >= (battle_config.WOE_K_DELAY_AC_SHOWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AC_SHOWER >= (battle_config.K_DELAY_AC_SHOWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AC_SHOWER = sd->K_LOCK_AC_SHOWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AC_SHOWER = gettick() + battle_config.WOE_K_DELAY_AC_SHOWER;
				else
					sd->K_CHK_AC_SHOWER = gettick() + battle_config.K_DELAY_AC_SHOWER;

				sd->K_LOCK_AC_SHOWER = 0;
			}
			break;
		case TF_POISON:
			if(DIFF_TICK(sd->K_CHK_TF_POISON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TF_POISON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TF_POISON >= (battle_config.WOE_K_DELAY_TF_POISON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TF_POISON >= (battle_config.K_DELAY_TF_POISON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TF_POISON = sd->K_LOCK_TF_POISON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TF_POISON = gettick() + battle_config.WOE_K_DELAY_TF_POISON;
				else
					sd->K_CHK_TF_POISON = gettick() + battle_config.K_DELAY_TF_POISON;

				sd->K_LOCK_TF_POISON = 0;
			}
			break;
		case KN_PIERCE:
			if(DIFF_TICK(sd->K_CHK_KN_PIERCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_PIERCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_PIERCE >= (battle_config.WOE_K_DELAY_KN_PIERCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_PIERCE >= (battle_config.K_DELAY_KN_PIERCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_PIERCE = sd->K_LOCK_KN_PIERCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_PIERCE = gettick() + battle_config.WOE_K_DELAY_KN_PIERCE;
				else
					sd->K_CHK_KN_PIERCE = gettick() + battle_config.K_DELAY_KN_PIERCE;

				sd->K_LOCK_KN_PIERCE = 0;
			}
			break;
		case KN_BRANDISHSPEAR:
			if(DIFF_TICK(sd->K_CHK_KN_BRANDISHSPEAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_BRANDISHSPEAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_BRANDISHSPEAR >= (battle_config.WOE_K_DELAY_KN_BRANDISHSPEAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_BRANDISHSPEAR >= (battle_config.K_DELAY_KN_BRANDISHSPEAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_BRANDISHSPEAR = sd->K_LOCK_KN_BRANDISHSPEAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_BRANDISHSPEAR = gettick() + battle_config.WOE_K_DELAY_KN_BRANDISHSPEAR;
				else
					sd->K_CHK_KN_BRANDISHSPEAR = gettick() + battle_config.K_DELAY_KN_BRANDISHSPEAR;

				sd->K_LOCK_KN_BRANDISHSPEAR = 0;
			}
			break;
		case KN_SPEARSTAB:
			if(DIFF_TICK(sd->K_CHK_KN_SPEARSTAB,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_SPEARSTAB - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_SPEARSTAB >= (battle_config.WOE_K_DELAY_KN_SPEARSTAB/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_SPEARSTAB >= (battle_config.K_DELAY_KN_SPEARSTAB/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_SPEARSTAB = sd->K_LOCK_KN_SPEARSTAB +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_SPEARSTAB = gettick() + battle_config.WOE_K_DELAY_KN_SPEARSTAB;
				else
					sd->K_CHK_KN_SPEARSTAB = gettick() + battle_config.K_DELAY_KN_SPEARSTAB;

				sd->K_LOCK_KN_SPEARSTAB = 0;
			}
			break;
		case KN_SPEARBOOMERANG:
			if(DIFF_TICK(sd->K_CHK_KN_SPEARBOOMERANG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_SPEARBOOMERANG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_SPEARBOOMERANG >= (battle_config.WOE_K_DELAY_KN_SPEARBOOMERANG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_SPEARBOOMERANG >= (battle_config.K_DELAY_KN_SPEARBOOMERANG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_SPEARBOOMERANG = sd->K_LOCK_KN_SPEARBOOMERANG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_SPEARBOOMERANG = gettick() + battle_config.WOE_K_DELAY_KN_SPEARBOOMERANG;
				else
					sd->K_CHK_KN_SPEARBOOMERANG = gettick() + battle_config.K_DELAY_KN_SPEARBOOMERANG;

				sd->K_LOCK_KN_SPEARBOOMERANG = 0;
			}
			break;
		case KN_BOWLINGBASH:
			if(DIFF_TICK(sd->K_CHK_KN_BOWLINGBASH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_BOWLINGBASH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_BOWLINGBASH >= (battle_config.WOE_K_DELAY_KN_BOWLINGBASH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_BOWLINGBASH >= (battle_config.K_DELAY_KN_BOWLINGBASH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_BOWLINGBASH = sd->K_LOCK_KN_BOWLINGBASH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_BOWLINGBASH = gettick() + battle_config.WOE_K_DELAY_KN_BOWLINGBASH;
				else
					sd->K_CHK_KN_BOWLINGBASH = gettick() + battle_config.K_DELAY_KN_BOWLINGBASH;

				sd->K_LOCK_KN_BOWLINGBASH = 0;
			}
			break;
		case PR_LEXDIVINA:
			if(DIFF_TICK(sd->K_CHK_PR_LEXDIVINA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PR_LEXDIVINA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PR_LEXDIVINA >= (battle_config.WOE_K_DELAY_PR_LEXDIVINA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PR_LEXDIVINA >= (battle_config.K_DELAY_PR_LEXDIVINA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PR_LEXDIVINA = sd->K_LOCK_PR_LEXDIVINA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PR_LEXDIVINA = gettick() + battle_config.WOE_K_DELAY_PR_LEXDIVINA;
				else
					sd->K_CHK_PR_LEXDIVINA = gettick() + battle_config.K_DELAY_PR_LEXDIVINA;

				sd->K_LOCK_PR_LEXDIVINA = 0;
			}
			break;
		case PR_TURNUNDEAD:
			if(DIFF_TICK(sd->K_CHK_PR_TURNUNDEAD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PR_TURNUNDEAD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PR_TURNUNDEAD >= (battle_config.WOE_K_DELAY_PR_TURNUNDEAD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PR_TURNUNDEAD >= (battle_config.K_DELAY_PR_TURNUNDEAD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PR_TURNUNDEAD = sd->K_LOCK_PR_TURNUNDEAD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PR_TURNUNDEAD = gettick() + battle_config.WOE_K_DELAY_PR_TURNUNDEAD;
				else
					sd->K_CHK_PR_TURNUNDEAD = gettick() + battle_config.K_DELAY_PR_TURNUNDEAD;

				sd->K_LOCK_PR_TURNUNDEAD = 0;
			}
			break;
		case PR_LEXAETERNA:
			if(DIFF_TICK(sd->K_CHK_PR_LEXAETERNA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PR_LEXAETERNA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PR_LEXAETERNA >= (battle_config.WOE_K_DELAY_PR_LEXAETERNA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PR_LEXAETERNA >= (battle_config.K_DELAY_PR_LEXAETERNA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PR_LEXAETERNA = sd->K_LOCK_PR_LEXAETERNA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PR_LEXAETERNA = gettick() + battle_config.WOE_K_DELAY_PR_LEXAETERNA;
				else
					sd->K_CHK_PR_LEXAETERNA = gettick() + battle_config.K_DELAY_PR_LEXAETERNA;

				sd->K_LOCK_PR_LEXAETERNA = 0;
			}
			break;
		case PR_MAGNUS:
			if(DIFF_TICK(sd->K_CHK_PR_MAGNUS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PR_MAGNUS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PR_MAGNUS >= (battle_config.WOE_K_DELAY_PR_MAGNUS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PR_MAGNUS >= (battle_config.K_DELAY_PR_MAGNUS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PR_MAGNUS = sd->K_LOCK_PR_MAGNUS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PR_MAGNUS = gettick() + battle_config.WOE_K_DELAY_PR_MAGNUS;
				else
					sd->K_CHK_PR_MAGNUS = gettick() + battle_config.K_DELAY_PR_MAGNUS;

				sd->K_LOCK_PR_MAGNUS = 0;
			}
			break;
		case WZ_FIREPILLAR:
			if(DIFF_TICK(sd->K_CHK_WZ_FIREPILLAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_FIREPILLAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_FIREPILLAR >= (battle_config.WOE_K_DELAY_WZ_FIREPILLAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_FIREPILLAR >= (battle_config.K_DELAY_WZ_FIREPILLAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_FIREPILLAR = sd->K_LOCK_WZ_FIREPILLAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_FIREPILLAR = gettick() + battle_config.WOE_K_DELAY_WZ_FIREPILLAR;
				else
					sd->K_CHK_WZ_FIREPILLAR = gettick() + battle_config.K_DELAY_WZ_FIREPILLAR;

				sd->K_LOCK_WZ_FIREPILLAR = 0;
			}
			break;
		case WZ_SIGHTRASHER:
			if(DIFF_TICK(sd->K_CHK_WZ_SIGHTRASHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_SIGHTRASHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_SIGHTRASHER >= (battle_config.WOE_K_DELAY_WZ_SIGHTRASHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_SIGHTRASHER >= (battle_config.K_DELAY_WZ_SIGHTRASHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_SIGHTRASHER = sd->K_LOCK_WZ_SIGHTRASHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_SIGHTRASHER = gettick() + battle_config.WOE_K_DELAY_WZ_SIGHTRASHER;
				else
					sd->K_CHK_WZ_SIGHTRASHER = gettick() + battle_config.K_DELAY_WZ_SIGHTRASHER;

				sd->K_LOCK_WZ_SIGHTRASHER = 0;
			}
			break;
		case WZ_FIREIVY:
			if(DIFF_TICK(sd->K_CHK_WZ_FIREIVY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_FIREIVY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_FIREIVY >= (battle_config.WOE_K_DELAY_WZ_FIREIVY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_FIREIVY >= (battle_config.K_DELAY_WZ_FIREIVY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_FIREIVY = sd->K_LOCK_WZ_FIREIVY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_FIREIVY = gettick() + battle_config.WOE_K_DELAY_WZ_FIREIVY;
				else
					sd->K_CHK_WZ_FIREIVY = gettick() + battle_config.K_DELAY_WZ_FIREIVY;

				sd->K_LOCK_WZ_FIREIVY = 0;
			}
			break;
		case WZ_METEOR:
			if(DIFF_TICK(sd->K_CHK_WZ_METEOR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_METEOR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_METEOR >= (battle_config.WOE_K_DELAY_WZ_METEOR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_METEOR >= (battle_config.K_DELAY_WZ_METEOR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_METEOR = sd->K_LOCK_WZ_METEOR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_METEOR = gettick() + battle_config.WOE_K_DELAY_WZ_METEOR;
				else
					sd->K_CHK_WZ_METEOR = gettick() + battle_config.K_DELAY_WZ_METEOR;

				sd->K_LOCK_WZ_METEOR = 0;
			}
			break;
		case WZ_JUPITEL:
			if(DIFF_TICK(sd->K_CHK_WZ_JUPITEL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_JUPITEL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_JUPITEL >= (battle_config.WOE_K_DELAY_WZ_JUPITEL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_JUPITEL >= (battle_config.K_DELAY_WZ_JUPITEL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_JUPITEL = sd->K_LOCK_WZ_JUPITEL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_JUPITEL = gettick() + battle_config.WOE_K_DELAY_WZ_JUPITEL;
				else
					sd->K_CHK_WZ_JUPITEL = gettick() + battle_config.K_DELAY_WZ_JUPITEL;

				sd->K_LOCK_WZ_JUPITEL = 0;
			}
			break;
		case WZ_VERMILION:
			if(DIFF_TICK(sd->K_CHK_WZ_VERMILION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_VERMILION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_VERMILION >= (battle_config.WOE_K_DELAY_WZ_VERMILION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_VERMILION >= (battle_config.K_DELAY_WZ_VERMILION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_VERMILION = sd->K_LOCK_WZ_VERMILION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_VERMILION = gettick() + battle_config.WOE_K_DELAY_WZ_VERMILION;
				else
					sd->K_CHK_WZ_VERMILION = gettick() + battle_config.K_DELAY_WZ_VERMILION;

				sd->K_LOCK_WZ_VERMILION = 0;
			}
			break;
		case WZ_WATERBALL:
			if(DIFF_TICK(sd->K_CHK_WZ_WATERBALL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_WATERBALL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_WATERBALL >= (battle_config.WOE_K_DELAY_WZ_WATERBALL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_WATERBALL >= (battle_config.K_DELAY_WZ_WATERBALL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_WATERBALL = sd->K_LOCK_WZ_WATERBALL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_WATERBALL = gettick() + battle_config.WOE_K_DELAY_WZ_WATERBALL;
				else
					sd->K_CHK_WZ_WATERBALL = gettick() + battle_config.K_DELAY_WZ_WATERBALL;

				sd->K_LOCK_WZ_WATERBALL = 0;
			}
			break;
		case WZ_ICEWALL:
			if(DIFF_TICK(sd->K_CHK_WZ_ICEWALL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_ICEWALL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_ICEWALL >= (battle_config.WOE_K_DELAY_WZ_ICEWALL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_ICEWALL >= (battle_config.K_DELAY_WZ_ICEWALL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_ICEWALL = sd->K_LOCK_WZ_ICEWALL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_ICEWALL = gettick() + battle_config.WOE_K_DELAY_WZ_ICEWALL;
				else
					sd->K_CHK_WZ_ICEWALL = gettick() + battle_config.K_DELAY_WZ_ICEWALL;

				sd->K_LOCK_WZ_ICEWALL = 0;
			}
			break;
		case WZ_FROSTNOVA:
			if(DIFF_TICK(sd->K_CHK_WZ_FROSTNOVA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_FROSTNOVA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_FROSTNOVA >= (battle_config.WOE_K_DELAY_WZ_FROSTNOVA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_FROSTNOVA >= (battle_config.K_DELAY_WZ_FROSTNOVA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_FROSTNOVA = sd->K_LOCK_WZ_FROSTNOVA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_FROSTNOVA = gettick() + battle_config.WOE_K_DELAY_WZ_FROSTNOVA;
				else
					sd->K_CHK_WZ_FROSTNOVA = gettick() + battle_config.K_DELAY_WZ_FROSTNOVA;

				sd->K_LOCK_WZ_FROSTNOVA = 0;
			}
			break;
		case WZ_STORMGUST:
			if(DIFF_TICK(sd->K_CHK_WZ_STORMGUST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_STORMGUST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_STORMGUST >= (battle_config.WOE_K_DELAY_WZ_STORMGUST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_STORMGUST >= (battle_config.K_DELAY_WZ_STORMGUST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_STORMGUST = sd->K_LOCK_WZ_STORMGUST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_STORMGUST = gettick() + battle_config.WOE_K_DELAY_WZ_STORMGUST;
				else
					sd->K_CHK_WZ_STORMGUST = gettick() + battle_config.K_DELAY_WZ_STORMGUST;

				sd->K_LOCK_WZ_STORMGUST = 0;
			}
			break;
		case WZ_EARTHSPIKE:
			if(DIFF_TICK(sd->K_CHK_WZ_EARTHSPIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_EARTHSPIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_EARTHSPIKE >= (battle_config.WOE_K_DELAY_WZ_EARTHSPIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_EARTHSPIKE >= (battle_config.K_DELAY_WZ_EARTHSPIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_EARTHSPIKE = sd->K_LOCK_WZ_EARTHSPIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_EARTHSPIKE = gettick() + battle_config.WOE_K_DELAY_WZ_EARTHSPIKE;
				else
					sd->K_CHK_WZ_EARTHSPIKE = gettick() + battle_config.K_DELAY_WZ_EARTHSPIKE;

				sd->K_LOCK_WZ_EARTHSPIKE = 0;
			}
			break;
		case WZ_HEAVENDRIVE:
			if(DIFF_TICK(sd->K_CHK_WZ_HEAVENDRIVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_HEAVENDRIVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_HEAVENDRIVE >= (battle_config.WOE_K_DELAY_WZ_HEAVENDRIVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_HEAVENDRIVE >= (battle_config.K_DELAY_WZ_HEAVENDRIVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_HEAVENDRIVE = sd->K_LOCK_WZ_HEAVENDRIVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_HEAVENDRIVE = gettick() + battle_config.WOE_K_DELAY_WZ_HEAVENDRIVE;
				else
					sd->K_CHK_WZ_HEAVENDRIVE = gettick() + battle_config.K_DELAY_WZ_HEAVENDRIVE;

				sd->K_LOCK_WZ_HEAVENDRIVE = 0;
			}
			break;
		case WZ_QUAGMIRE:
			if(DIFF_TICK(sd->K_CHK_WZ_QUAGMIRE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_QUAGMIRE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_QUAGMIRE >= (battle_config.WOE_K_DELAY_WZ_QUAGMIRE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_QUAGMIRE >= (battle_config.K_DELAY_WZ_QUAGMIRE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_QUAGMIRE = sd->K_LOCK_WZ_QUAGMIRE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_QUAGMIRE = gettick() + battle_config.WOE_K_DELAY_WZ_QUAGMIRE;
				else
					sd->K_CHK_WZ_QUAGMIRE = gettick() + battle_config.K_DELAY_WZ_QUAGMIRE;

				sd->K_LOCK_WZ_QUAGMIRE = 0;
			}
			break;
		case WZ_ESTIMATION:
			if(DIFF_TICK(sd->K_CHK_WZ_ESTIMATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_ESTIMATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_ESTIMATION >= (battle_config.WOE_K_DELAY_WZ_ESTIMATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_ESTIMATION >= (battle_config.K_DELAY_WZ_ESTIMATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_ESTIMATION = sd->K_LOCK_WZ_ESTIMATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_ESTIMATION = gettick() + battle_config.WOE_K_DELAY_WZ_ESTIMATION;
				else
					sd->K_CHK_WZ_ESTIMATION = gettick() + battle_config.K_DELAY_WZ_ESTIMATION;

				sd->K_LOCK_WZ_ESTIMATION = 0;
			}
			break;
		case BS_HAMMERFALL:
			if(DIFF_TICK(sd->K_CHK_BS_HAMMERFALL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BS_HAMMERFALL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BS_HAMMERFALL >= (battle_config.WOE_K_DELAY_BS_HAMMERFALL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BS_HAMMERFALL >= (battle_config.K_DELAY_BS_HAMMERFALL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BS_HAMMERFALL = sd->K_LOCK_BS_HAMMERFALL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BS_HAMMERFALL = gettick() + battle_config.WOE_K_DELAY_BS_HAMMERFALL;
				else
					sd->K_CHK_BS_HAMMERFALL = gettick() + battle_config.K_DELAY_BS_HAMMERFALL;

				sd->K_LOCK_BS_HAMMERFALL = 0;
			}
			break;
		case HT_BLITZBEAT:
			if(DIFF_TICK(sd->K_CHK_HT_BLITZBEAT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HT_BLITZBEAT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HT_BLITZBEAT >= (battle_config.WOE_K_DELAY_HT_BLITZBEAT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HT_BLITZBEAT >= (battle_config.K_DELAY_HT_BLITZBEAT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HT_BLITZBEAT = sd->K_LOCK_HT_BLITZBEAT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HT_BLITZBEAT = gettick() + battle_config.WOE_K_DELAY_HT_BLITZBEAT;
				else
					sd->K_CHK_HT_BLITZBEAT = gettick() + battle_config.K_DELAY_HT_BLITZBEAT;

				sd->K_LOCK_HT_BLITZBEAT = 0;
			}
			break;
		case AS_SONICBLOW:
			if(DIFF_TICK(sd->K_CHK_AS_SONICBLOW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AS_SONICBLOW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AS_SONICBLOW >= (battle_config.WOE_K_DELAY_AS_SONICBLOW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AS_SONICBLOW >= (battle_config.K_DELAY_AS_SONICBLOW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AS_SONICBLOW = sd->K_LOCK_AS_SONICBLOW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AS_SONICBLOW = gettick() + battle_config.WOE_K_DELAY_AS_SONICBLOW;
				else
					sd->K_CHK_AS_SONICBLOW = gettick() + battle_config.K_DELAY_AS_SONICBLOW;

				sd->K_LOCK_AS_SONICBLOW = 0;
			}
			break;
		case AS_GRIMTOOTH:
			if(DIFF_TICK(sd->K_CHK_AS_GRIMTOOTH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AS_GRIMTOOTH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AS_GRIMTOOTH >= (battle_config.WOE_K_DELAY_AS_GRIMTOOTH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AS_GRIMTOOTH >= (battle_config.K_DELAY_AS_GRIMTOOTH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AS_GRIMTOOTH = sd->K_LOCK_AS_GRIMTOOTH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AS_GRIMTOOTH = gettick() + battle_config.WOE_K_DELAY_AS_GRIMTOOTH;
				else
					sd->K_CHK_AS_GRIMTOOTH = gettick() + battle_config.K_DELAY_AS_GRIMTOOTH;

				sd->K_LOCK_AS_GRIMTOOTH = 0;
			}
			break;
		case AC_CHARGEARROW:
			if(DIFF_TICK(sd->K_CHK_AC_CHARGEARROW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AC_CHARGEARROW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AC_CHARGEARROW >= (battle_config.WOE_K_DELAY_AC_CHARGEARROW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AC_CHARGEARROW >= (battle_config.K_DELAY_AC_CHARGEARROW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AC_CHARGEARROW = sd->K_LOCK_AC_CHARGEARROW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AC_CHARGEARROW = gettick() + battle_config.WOE_K_DELAY_AC_CHARGEARROW;
				else
					sd->K_CHK_AC_CHARGEARROW = gettick() + battle_config.K_DELAY_AC_CHARGEARROW;

				sd->K_LOCK_AC_CHARGEARROW = 0;
			}
			break;
		case TF_BACKSLIDING:
			if(DIFF_TICK(sd->K_CHK_TF_BACKSLIDING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TF_BACKSLIDING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TF_BACKSLIDING >= (battle_config.WOE_K_DELAY_TF_BACKSLIDING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TF_BACKSLIDING >= (battle_config.K_DELAY_TF_BACKSLIDING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TF_BACKSLIDING = sd->K_LOCK_TF_BACKSLIDING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TF_BACKSLIDING = gettick() + battle_config.WOE_K_DELAY_TF_BACKSLIDING;
				else
					sd->K_CHK_TF_BACKSLIDING = gettick() + battle_config.K_DELAY_TF_BACKSLIDING;

				sd->K_LOCK_TF_BACKSLIDING = 0;
			}
			break;
		case MC_CARTREVOLUTION:
			if(DIFF_TICK(sd->K_CHK_MC_CARTREVOLUTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MC_CARTREVOLUTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MC_CARTREVOLUTION >= (battle_config.WOE_K_DELAY_MC_CARTREVOLUTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MC_CARTREVOLUTION >= (battle_config.K_DELAY_MC_CARTREVOLUTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MC_CARTREVOLUTION = sd->K_LOCK_MC_CARTREVOLUTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MC_CARTREVOLUTION = gettick() + battle_config.WOE_K_DELAY_MC_CARTREVOLUTION;
				else
					sd->K_CHK_MC_CARTREVOLUTION = gettick() + battle_config.K_DELAY_MC_CARTREVOLUTION;

				sd->K_LOCK_MC_CARTREVOLUTION = 0;
			}
			break;
		case AL_HOLYLIGHT:
			if(DIFF_TICK(sd->K_CHK_AL_HOLYLIGHT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AL_HOLYLIGHT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AL_HOLYLIGHT >= (battle_config.WOE_K_DELAY_AL_HOLYLIGHT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AL_HOLYLIGHT >= (battle_config.K_DELAY_AL_HOLYLIGHT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AL_HOLYLIGHT = sd->K_LOCK_AL_HOLYLIGHT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AL_HOLYLIGHT = gettick() + battle_config.WOE_K_DELAY_AL_HOLYLIGHT;
				else
					sd->K_CHK_AL_HOLYLIGHT = gettick() + battle_config.K_DELAY_AL_HOLYLIGHT;

				sd->K_LOCK_AL_HOLYLIGHT = 0;
			}
			break;
		case RG_BACKSTAP:
			if(DIFF_TICK(sd->K_CHK_RG_BACKSTAP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_BACKSTAP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_BACKSTAP >= (battle_config.WOE_K_DELAY_RG_BACKSTAP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_BACKSTAP >= (battle_config.K_DELAY_RG_BACKSTAP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_BACKSTAP = sd->K_LOCK_RG_BACKSTAP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_BACKSTAP = gettick() + battle_config.WOE_K_DELAY_RG_BACKSTAP;
				else
					sd->K_CHK_RG_BACKSTAP = gettick() + battle_config.K_DELAY_RG_BACKSTAP;

				sd->K_LOCK_RG_BACKSTAP = 0;
			}
			break;
		case RG_RAID:
			if(DIFF_TICK(sd->K_CHK_RG_RAID,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_RAID - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_RAID >= (battle_config.WOE_K_DELAY_RG_RAID/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_RAID >= (battle_config.K_DELAY_RG_RAID/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_RAID = sd->K_LOCK_RG_RAID +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_RAID = gettick() + battle_config.WOE_K_DELAY_RG_RAID;
				else
					sd->K_CHK_RG_RAID = gettick() + battle_config.K_DELAY_RG_RAID;

				sd->K_LOCK_RG_RAID = 0;
			}
			break;
		case RG_GRAFFITI:
			if(DIFF_TICK(sd->K_CHK_RG_GRAFFITI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_GRAFFITI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_GRAFFITI >= (battle_config.WOE_K_DELAY_RG_GRAFFITI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_GRAFFITI >= (battle_config.K_DELAY_RG_GRAFFITI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_GRAFFITI = sd->K_LOCK_RG_GRAFFITI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_GRAFFITI = gettick() + battle_config.WOE_K_DELAY_RG_GRAFFITI;
				else
					sd->K_CHK_RG_GRAFFITI = gettick() + battle_config.K_DELAY_RG_GRAFFITI;

				sd->K_LOCK_RG_GRAFFITI = 0;
			}
			break;
		case RG_FLAGGRAFFITI:
			if(DIFF_TICK(sd->K_CHK_RG_FLAGGRAFFITI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_FLAGGRAFFITI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_FLAGGRAFFITI >= (battle_config.WOE_K_DELAY_RG_FLAGGRAFFITI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_FLAGGRAFFITI >= (battle_config.K_DELAY_RG_FLAGGRAFFITI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_FLAGGRAFFITI = sd->K_LOCK_RG_FLAGGRAFFITI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_FLAGGRAFFITI = gettick() + battle_config.WOE_K_DELAY_RG_FLAGGRAFFITI;
				else
					sd->K_CHK_RG_FLAGGRAFFITI = gettick() + battle_config.K_DELAY_RG_FLAGGRAFFITI;

				sd->K_LOCK_RG_FLAGGRAFFITI = 0;
			}
			break;
		case RG_COMPULSION:
			if(DIFF_TICK(sd->K_CHK_RG_COMPULSION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_COMPULSION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_COMPULSION >= (battle_config.WOE_K_DELAY_RG_COMPULSION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_COMPULSION >= (battle_config.K_DELAY_RG_COMPULSION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_COMPULSION = sd->K_LOCK_RG_COMPULSION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_COMPULSION = gettick() + battle_config.WOE_K_DELAY_RG_COMPULSION;
				else
					sd->K_CHK_RG_COMPULSION = gettick() + battle_config.K_DELAY_RG_COMPULSION;

				sd->K_LOCK_RG_COMPULSION = 0;
			}
			break;
		case RG_PLAGIARISM:
			if(DIFF_TICK(sd->K_CHK_RG_PLAGIARISM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_PLAGIARISM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_PLAGIARISM >= (battle_config.WOE_K_DELAY_RG_PLAGIARISM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_PLAGIARISM >= (battle_config.K_DELAY_RG_PLAGIARISM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_PLAGIARISM = sd->K_LOCK_RG_PLAGIARISM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_PLAGIARISM = gettick() + battle_config.WOE_K_DELAY_RG_PLAGIARISM;
				else
					sd->K_CHK_RG_PLAGIARISM = gettick() + battle_config.K_DELAY_RG_PLAGIARISM;

				sd->K_LOCK_RG_PLAGIARISM = 0;
			}
			break;
		case AM_DEMONSTRATION:
			if(DIFF_TICK(sd->K_CHK_AM_DEMONSTRATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_DEMONSTRATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_DEMONSTRATION >= (battle_config.WOE_K_DELAY_AM_DEMONSTRATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_DEMONSTRATION >= (battle_config.K_DELAY_AM_DEMONSTRATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_DEMONSTRATION = sd->K_LOCK_AM_DEMONSTRATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_DEMONSTRATION = gettick() + battle_config.WOE_K_DELAY_AM_DEMONSTRATION;
				else
					sd->K_CHK_AM_DEMONSTRATION = gettick() + battle_config.K_DELAY_AM_DEMONSTRATION;

				sd->K_LOCK_AM_DEMONSTRATION = 0;
			}
			break;
		case AM_ACIDTERROR:
			if(DIFF_TICK(sd->K_CHK_AM_ACIDTERROR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_ACIDTERROR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_ACIDTERROR >= (battle_config.WOE_K_DELAY_AM_ACIDTERROR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_ACIDTERROR >= (battle_config.K_DELAY_AM_ACIDTERROR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_ACIDTERROR = sd->K_LOCK_AM_ACIDTERROR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_ACIDTERROR = gettick() + battle_config.WOE_K_DELAY_AM_ACIDTERROR;
				else
					sd->K_CHK_AM_ACIDTERROR = gettick() + battle_config.K_DELAY_AM_ACIDTERROR;

				sd->K_LOCK_AM_ACIDTERROR = 0;
			}
			break;
		case AM_POTIONPITCHER:
			if(DIFF_TICK(sd->K_CHK_AM_POTIONPITCHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_POTIONPITCHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_POTIONPITCHER >= (battle_config.WOE_K_DELAY_AM_POTIONPITCHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_POTIONPITCHER >= (battle_config.K_DELAY_AM_POTIONPITCHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_POTIONPITCHER = sd->K_LOCK_AM_POTIONPITCHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_POTIONPITCHER = gettick() + battle_config.WOE_K_DELAY_AM_POTIONPITCHER;
				else
					sd->K_CHK_AM_POTIONPITCHER = gettick() + battle_config.K_DELAY_AM_POTIONPITCHER;

				sd->K_LOCK_AM_POTIONPITCHER = 0;
			}
			break;
		case AM_CANNIBALIZE:
			if(DIFF_TICK(sd->K_CHK_AM_CANNIBALIZE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_CANNIBALIZE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_CANNIBALIZE >= (battle_config.WOE_K_DELAY_AM_CANNIBALIZE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_CANNIBALIZE >= (battle_config.K_DELAY_AM_CANNIBALIZE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_CANNIBALIZE = sd->K_LOCK_AM_CANNIBALIZE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_CANNIBALIZE = gettick() + battle_config.WOE_K_DELAY_AM_CANNIBALIZE;
				else
					sd->K_CHK_AM_CANNIBALIZE = gettick() + battle_config.K_DELAY_AM_CANNIBALIZE;

				sd->K_LOCK_AM_CANNIBALIZE = 0;
			}
			break;
		case AM_SPHEREMINE:
			if(DIFF_TICK(sd->K_CHK_AM_SPHEREMINE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_SPHEREMINE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_SPHEREMINE >= (battle_config.WOE_K_DELAY_AM_SPHEREMINE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_SPHEREMINE >= (battle_config.K_DELAY_AM_SPHEREMINE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_SPHEREMINE = sd->K_LOCK_AM_SPHEREMINE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_SPHEREMINE = gettick() + battle_config.WOE_K_DELAY_AM_SPHEREMINE;
				else
					sd->K_CHK_AM_SPHEREMINE = gettick() + battle_config.K_DELAY_AM_SPHEREMINE;

				sd->K_LOCK_AM_SPHEREMINE = 0;
			}
			break;
		case AM_FLAMECONTROL:
			if(DIFF_TICK(sd->K_CHK_AM_FLAMECONTROL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_FLAMECONTROL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_FLAMECONTROL >= (battle_config.WOE_K_DELAY_AM_FLAMECONTROL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_FLAMECONTROL >= (battle_config.K_DELAY_AM_FLAMECONTROL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_FLAMECONTROL = sd->K_LOCK_AM_FLAMECONTROL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_FLAMECONTROL = gettick() + battle_config.WOE_K_DELAY_AM_FLAMECONTROL;
				else
					sd->K_CHK_AM_FLAMECONTROL = gettick() + battle_config.K_DELAY_AM_FLAMECONTROL;

				sd->K_LOCK_AM_FLAMECONTROL = 0;
			}
			break;
		case AM_DRILLMASTER:
			if(DIFF_TICK(sd->K_CHK_AM_DRILLMASTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AM_DRILLMASTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AM_DRILLMASTER >= (battle_config.WOE_K_DELAY_AM_DRILLMASTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AM_DRILLMASTER >= (battle_config.K_DELAY_AM_DRILLMASTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AM_DRILLMASTER = sd->K_LOCK_AM_DRILLMASTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AM_DRILLMASTER = gettick() + battle_config.WOE_K_DELAY_AM_DRILLMASTER;
				else
					sd->K_CHK_AM_DRILLMASTER = gettick() + battle_config.K_DELAY_AM_DRILLMASTER;

				sd->K_LOCK_AM_DRILLMASTER = 0;
			}
			break;
		case CR_SHIELDBOOMERANG:
			if(DIFF_TICK(sd->K_CHK_CR_SHIELDBOOMERANG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_SHIELDBOOMERANG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_SHIELDBOOMERANG >= (battle_config.WOE_K_DELAY_CR_SHIELDBOOMERANG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_SHIELDBOOMERANG >= (battle_config.K_DELAY_CR_SHIELDBOOMERANG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_SHIELDBOOMERANG = sd->K_LOCK_CR_SHIELDBOOMERANG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_SHIELDBOOMERANG = gettick() + battle_config.WOE_K_DELAY_CR_SHIELDBOOMERANG;
				else
					sd->K_CHK_CR_SHIELDBOOMERANG = gettick() + battle_config.K_DELAY_CR_SHIELDBOOMERANG;

				sd->K_LOCK_CR_SHIELDBOOMERANG = 0;
			}
			break;
		case CR_HOLYCROSS:
			if(DIFF_TICK(sd->K_CHK_CR_HOLYCROSS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_HOLYCROSS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_HOLYCROSS >= (battle_config.WOE_K_DELAY_CR_HOLYCROSS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_HOLYCROSS >= (battle_config.K_DELAY_CR_HOLYCROSS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_HOLYCROSS = sd->K_LOCK_CR_HOLYCROSS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_HOLYCROSS = gettick() + battle_config.WOE_K_DELAY_CR_HOLYCROSS;
				else
					sd->K_CHK_CR_HOLYCROSS = gettick() + battle_config.K_DELAY_CR_HOLYCROSS;

				sd->K_LOCK_CR_HOLYCROSS = 0;
			}
			break;
		case CR_GRANDCROSS:
			if(DIFF_TICK(sd->K_CHK_CR_GRANDCROSS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_GRANDCROSS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_GRANDCROSS >= (battle_config.WOE_K_DELAY_CR_GRANDCROSS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_GRANDCROSS >= (battle_config.K_DELAY_CR_GRANDCROSS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_GRANDCROSS = sd->K_LOCK_CR_GRANDCROSS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_GRANDCROSS = gettick() + battle_config.WOE_K_DELAY_CR_GRANDCROSS;
				else
					sd->K_CHK_CR_GRANDCROSS = gettick() + battle_config.K_DELAY_CR_GRANDCROSS;

				sd->K_LOCK_CR_GRANDCROSS = 0;
			}
			break;
		case MO_CALLSPIRITS:
			if(DIFF_TICK(sd->K_CHK_MO_CALLSPIRITS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_CALLSPIRITS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_CALLSPIRITS >= (battle_config.WOE_K_DELAY_MO_CALLSPIRITS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_CALLSPIRITS >= (battle_config.K_DELAY_MO_CALLSPIRITS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_CALLSPIRITS = sd->K_LOCK_MO_CALLSPIRITS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_CALLSPIRITS = gettick() + battle_config.WOE_K_DELAY_MO_CALLSPIRITS;
				else
					sd->K_CHK_MO_CALLSPIRITS = gettick() + battle_config.K_DELAY_MO_CALLSPIRITS;

				sd->K_LOCK_MO_CALLSPIRITS = 0;
			}
			break;
		case MO_ABSORBSPIRITS:
			if(DIFF_TICK(sd->K_CHK_MO_ABSORBSPIRITS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_ABSORBSPIRITS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_ABSORBSPIRITS >= (battle_config.WOE_K_DELAY_MO_ABSORBSPIRITS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_ABSORBSPIRITS >= (battle_config.K_DELAY_MO_ABSORBSPIRITS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_ABSORBSPIRITS = sd->K_LOCK_MO_ABSORBSPIRITS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_ABSORBSPIRITS = gettick() + battle_config.WOE_K_DELAY_MO_ABSORBSPIRITS;
				else
					sd->K_CHK_MO_ABSORBSPIRITS = gettick() + battle_config.K_DELAY_MO_ABSORBSPIRITS;

				sd->K_LOCK_MO_ABSORBSPIRITS = 0;
			}
			break;
		case MO_BODYRELOCATION:
			if(DIFF_TICK(sd->K_CHK_MO_BODYRELOCATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_BODYRELOCATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_BODYRELOCATION >= (battle_config.WOE_K_DELAY_MO_BODYRELOCATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_BODYRELOCATION >= (battle_config.K_DELAY_MO_BODYRELOCATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_BODYRELOCATION = sd->K_LOCK_MO_BODYRELOCATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_BODYRELOCATION = gettick() + battle_config.WOE_K_DELAY_MO_BODYRELOCATION;
				else
					sd->K_CHK_MO_BODYRELOCATION = gettick() + battle_config.K_DELAY_MO_BODYRELOCATION;

				sd->K_LOCK_MO_BODYRELOCATION = 0;
			}
			break;
		case MO_INVESTIGATE:
			if(DIFF_TICK(sd->K_CHK_MO_INVESTIGATE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_INVESTIGATE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_INVESTIGATE >= (battle_config.WOE_K_DELAY_MO_INVESTIGATE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_INVESTIGATE >= (battle_config.K_DELAY_MO_INVESTIGATE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_INVESTIGATE = sd->K_LOCK_MO_INVESTIGATE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_INVESTIGATE = gettick() + battle_config.WOE_K_DELAY_MO_INVESTIGATE;
				else
					sd->K_CHK_MO_INVESTIGATE = gettick() + battle_config.K_DELAY_MO_INVESTIGATE;

				sd->K_LOCK_MO_INVESTIGATE = 0;
			}
			break;
		case MO_FINGEROFFENSIVE:
			if(DIFF_TICK(sd->K_CHK_MO_FINGEROFFENSIVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_FINGEROFFENSIVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_FINGEROFFENSIVE >= (battle_config.WOE_K_DELAY_MO_FINGEROFFENSIVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_FINGEROFFENSIVE >= (battle_config.K_DELAY_MO_FINGEROFFENSIVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_FINGEROFFENSIVE = sd->K_LOCK_MO_FINGEROFFENSIVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_FINGEROFFENSIVE = gettick() + battle_config.WOE_K_DELAY_MO_FINGEROFFENSIVE;
				else
					sd->K_CHK_MO_FINGEROFFENSIVE = gettick() + battle_config.K_DELAY_MO_FINGEROFFENSIVE;

				sd->K_LOCK_MO_FINGEROFFENSIVE = 0;
			}
			break;
		case MO_EXPLOSIONSPIRITS:
			if(DIFF_TICK(sd->K_CHK_MO_EXPLOSIONSPIRITS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_EXPLOSIONSPIRITS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_EXPLOSIONSPIRITS >= (battle_config.WOE_K_DELAY_MO_EXPLOSIONSPIRITS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_EXPLOSIONSPIRITS >= (battle_config.K_DELAY_MO_EXPLOSIONSPIRITS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_EXPLOSIONSPIRITS = sd->K_LOCK_MO_EXPLOSIONSPIRITS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_EXPLOSIONSPIRITS = gettick() + battle_config.WOE_K_DELAY_MO_EXPLOSIONSPIRITS;
				else
					sd->K_CHK_MO_EXPLOSIONSPIRITS = gettick() + battle_config.K_DELAY_MO_EXPLOSIONSPIRITS;

				sd->K_LOCK_MO_EXPLOSIONSPIRITS = 0;
			}
			break;
		case MO_EXTREMITYFIST:
			if(DIFF_TICK(sd->K_CHK_MO_EXTREMITYFIST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_EXTREMITYFIST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_EXTREMITYFIST >= (battle_config.WOE_K_DELAY_MO_EXTREMITYFIST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_EXTREMITYFIST >= (battle_config.K_DELAY_MO_EXTREMITYFIST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_EXTREMITYFIST = sd->K_LOCK_MO_EXTREMITYFIST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_EXTREMITYFIST = gettick() + battle_config.WOE_K_DELAY_MO_EXTREMITYFIST;
				else
					sd->K_CHK_MO_EXTREMITYFIST = gettick() + battle_config.K_DELAY_MO_EXTREMITYFIST;

				sd->K_LOCK_MO_EXTREMITYFIST = 0;
			}
			if(DIFF_TICK(sd->K_CHK_MO_RELOCDELAY,gettick())> 0){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay after Body Relocation.",(sd->K_CHK_MO_RELOCDELAY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				sd->K_LOCK_MO_RELOCDELAY = 1;
			} else
				sd->K_LOCK_MO_RELOCDELAY = 0;
			break;
		case MO_CHAINCOMBO:
			if(DIFF_TICK(sd->K_CHK_MO_CHAINCOMBO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_CHAINCOMBO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_CHAINCOMBO >= (battle_config.WOE_K_DELAY_MO_CHAINCOMBO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_CHAINCOMBO >= (battle_config.K_DELAY_MO_CHAINCOMBO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_CHAINCOMBO = sd->K_LOCK_MO_CHAINCOMBO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_CHAINCOMBO = gettick() + battle_config.WOE_K_DELAY_MO_CHAINCOMBO;
				else
					sd->K_CHK_MO_CHAINCOMBO = gettick() + battle_config.K_DELAY_MO_CHAINCOMBO;

				sd->K_LOCK_MO_CHAINCOMBO = 0;
			}
			break;
		case MO_COMBOFINISH:
			if(DIFF_TICK(sd->K_CHK_MO_COMBOFINISH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_COMBOFINISH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_COMBOFINISH >= (battle_config.WOE_K_DELAY_MO_COMBOFINISH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_COMBOFINISH >= (battle_config.K_DELAY_MO_COMBOFINISH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_COMBOFINISH = sd->K_LOCK_MO_COMBOFINISH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_COMBOFINISH = gettick() + battle_config.WOE_K_DELAY_MO_COMBOFINISH;
				else
					sd->K_CHK_MO_COMBOFINISH = gettick() + battle_config.K_DELAY_MO_COMBOFINISH;

				sd->K_LOCK_MO_COMBOFINISH = 0;
			}
			break;
		case SA_CASTCANCEL:
			if(DIFF_TICK(sd->K_CHK_SA_CASTCANCEL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_CASTCANCEL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_CASTCANCEL >= (battle_config.WOE_K_DELAY_SA_CASTCANCEL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_CASTCANCEL >= (battle_config.K_DELAY_SA_CASTCANCEL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_CASTCANCEL = sd->K_LOCK_SA_CASTCANCEL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_CASTCANCEL = gettick() + battle_config.WOE_K_DELAY_SA_CASTCANCEL;
				else
					sd->K_CHK_SA_CASTCANCEL = gettick() + battle_config.K_DELAY_SA_CASTCANCEL;

				sd->K_LOCK_SA_CASTCANCEL = 0;
			}
			break;
		case SA_SPELLBREAKER:
			if(DIFF_TICK(sd->K_CHK_SA_SPELLBREAKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_SPELLBREAKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_SPELLBREAKER >= (battle_config.WOE_K_DELAY_SA_SPELLBREAKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_SPELLBREAKER >= (battle_config.K_DELAY_SA_SPELLBREAKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_SPELLBREAKER = sd->K_LOCK_SA_SPELLBREAKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_SPELLBREAKER = gettick() + battle_config.WOE_K_DELAY_SA_SPELLBREAKER;
				else
					sd->K_CHK_SA_SPELLBREAKER = gettick() + battle_config.K_DELAY_SA_SPELLBREAKER;

				sd->K_LOCK_SA_SPELLBREAKER = 0;
			}
			break;
		case SA_DISPELL:
			if(DIFF_TICK(sd->K_CHK_SA_DISPELL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_DISPELL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_DISPELL >= (battle_config.WOE_K_DELAY_SA_DISPELL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_DISPELL >= (battle_config.K_DELAY_SA_DISPELL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_DISPELL = sd->K_LOCK_SA_DISPELL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_DISPELL = gettick() + battle_config.WOE_K_DELAY_SA_DISPELL;
				else
					sd->K_CHK_SA_DISPELL = gettick() + battle_config.K_DELAY_SA_DISPELL;

				sd->K_LOCK_SA_DISPELL = 0;
			}
			break;
		case SA_ABRACADABRA:
			if(DIFF_TICK(sd->K_CHK_SA_ABRACADABRA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_ABRACADABRA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_ABRACADABRA >= (battle_config.WOE_K_DELAY_SA_ABRACADABRA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_ABRACADABRA >= (battle_config.K_DELAY_SA_ABRACADABRA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_ABRACADABRA = sd->K_LOCK_SA_ABRACADABRA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_ABRACADABRA = gettick() + battle_config.WOE_K_DELAY_SA_ABRACADABRA;
				else
					sd->K_CHK_SA_ABRACADABRA = gettick() + battle_config.K_DELAY_SA_ABRACADABRA;

				sd->K_LOCK_SA_ABRACADABRA = 0;
			}
			break;
		case SA_MONOCELL:
			if(DIFF_TICK(sd->K_CHK_SA_MONOCELL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_MONOCELL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_MONOCELL >= (battle_config.WOE_K_DELAY_SA_MONOCELL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_MONOCELL >= (battle_config.K_DELAY_SA_MONOCELL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_MONOCELL = sd->K_LOCK_SA_MONOCELL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_MONOCELL = gettick() + battle_config.WOE_K_DELAY_SA_MONOCELL;
				else
					sd->K_CHK_SA_MONOCELL = gettick() + battle_config.K_DELAY_SA_MONOCELL;

				sd->K_LOCK_SA_MONOCELL = 0;
			}
			break;
		case SA_CLASSCHANGE:
			if(DIFF_TICK(sd->K_CHK_SA_CLASSCHANGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_CLASSCHANGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_CLASSCHANGE >= (battle_config.WOE_K_DELAY_SA_CLASSCHANGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_CLASSCHANGE >= (battle_config.K_DELAY_SA_CLASSCHANGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_CLASSCHANGE = sd->K_LOCK_SA_CLASSCHANGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_CLASSCHANGE = gettick() + battle_config.WOE_K_DELAY_SA_CLASSCHANGE;
				else
					sd->K_CHK_SA_CLASSCHANGE = gettick() + battle_config.K_DELAY_SA_CLASSCHANGE;

				sd->K_LOCK_SA_CLASSCHANGE = 0;
			}
			break;
		case SA_SUMMONMONSTER:
			if(DIFF_TICK(sd->K_CHK_SA_SUMMONMONSTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_SUMMONMONSTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_SUMMONMONSTER >= (battle_config.WOE_K_DELAY_SA_SUMMONMONSTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_SUMMONMONSTER >= (battle_config.K_DELAY_SA_SUMMONMONSTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_SUMMONMONSTER = sd->K_LOCK_SA_SUMMONMONSTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_SUMMONMONSTER = gettick() + battle_config.WOE_K_DELAY_SA_SUMMONMONSTER;
				else
					sd->K_CHK_SA_SUMMONMONSTER = gettick() + battle_config.K_DELAY_SA_SUMMONMONSTER;

				sd->K_LOCK_SA_SUMMONMONSTER = 0;
			}
			break;
		case SA_REVERSEORCISH:
			if(DIFF_TICK(sd->K_CHK_SA_REVERSEORCISH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_REVERSEORCISH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_REVERSEORCISH >= (battle_config.WOE_K_DELAY_SA_REVERSEORCISH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_REVERSEORCISH >= (battle_config.K_DELAY_SA_REVERSEORCISH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_REVERSEORCISH = sd->K_LOCK_SA_REVERSEORCISH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_REVERSEORCISH = gettick() + battle_config.WOE_K_DELAY_SA_REVERSEORCISH;
				else
					sd->K_CHK_SA_REVERSEORCISH = gettick() + battle_config.K_DELAY_SA_REVERSEORCISH;

				sd->K_LOCK_SA_REVERSEORCISH = 0;
			}
			break;
		case SA_DEATH:
			if(DIFF_TICK(sd->K_CHK_SA_DEATH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_DEATH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_DEATH >= (battle_config.WOE_K_DELAY_SA_DEATH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_DEATH >= (battle_config.K_DELAY_SA_DEATH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_DEATH = sd->K_LOCK_SA_DEATH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_DEATH = gettick() + battle_config.WOE_K_DELAY_SA_DEATH;
				else
					sd->K_CHK_SA_DEATH = gettick() + battle_config.K_DELAY_SA_DEATH;

				sd->K_LOCK_SA_DEATH = 0;
			}
			break;
		case SA_FORTUNE:
			if(DIFF_TICK(sd->K_CHK_SA_FORTUNE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_FORTUNE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_FORTUNE >= (battle_config.WOE_K_DELAY_SA_FORTUNE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_FORTUNE >= (battle_config.K_DELAY_SA_FORTUNE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_FORTUNE = sd->K_LOCK_SA_FORTUNE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_FORTUNE = gettick() + battle_config.WOE_K_DELAY_SA_FORTUNE;
				else
					sd->K_CHK_SA_FORTUNE = gettick() + battle_config.K_DELAY_SA_FORTUNE;

				sd->K_LOCK_SA_FORTUNE = 0;
			}
			break;
		case SA_TAMINGMONSTER:
			if(DIFF_TICK(sd->K_CHK_SA_TAMINGMONSTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_TAMINGMONSTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_TAMINGMONSTER >= (battle_config.WOE_K_DELAY_SA_TAMINGMONSTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_TAMINGMONSTER >= (battle_config.K_DELAY_SA_TAMINGMONSTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_TAMINGMONSTER = sd->K_LOCK_SA_TAMINGMONSTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_TAMINGMONSTER = gettick() + battle_config.WOE_K_DELAY_SA_TAMINGMONSTER;
				else
					sd->K_CHK_SA_TAMINGMONSTER = gettick() + battle_config.K_DELAY_SA_TAMINGMONSTER;

				sd->K_LOCK_SA_TAMINGMONSTER = 0;
			}
			break;
		case SA_QUESTION:
			if(DIFF_TICK(sd->K_CHK_SA_QUESTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_QUESTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_QUESTION >= (battle_config.WOE_K_DELAY_SA_QUESTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_QUESTION >= (battle_config.K_DELAY_SA_QUESTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_QUESTION = sd->K_LOCK_SA_QUESTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_QUESTION = gettick() + battle_config.WOE_K_DELAY_SA_QUESTION;
				else
					sd->K_CHK_SA_QUESTION = gettick() + battle_config.K_DELAY_SA_QUESTION;

				sd->K_LOCK_SA_QUESTION = 0;
			}
			break;
		case SA_GRAVITY:
			if(DIFF_TICK(sd->K_CHK_SA_GRAVITY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_GRAVITY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_GRAVITY >= (battle_config.WOE_K_DELAY_SA_GRAVITY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_GRAVITY >= (battle_config.K_DELAY_SA_GRAVITY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_GRAVITY = sd->K_LOCK_SA_GRAVITY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_GRAVITY = gettick() + battle_config.WOE_K_DELAY_SA_GRAVITY;
				else
					sd->K_CHK_SA_GRAVITY = gettick() + battle_config.K_DELAY_SA_GRAVITY;

				sd->K_LOCK_SA_GRAVITY = 0;
			}
			break;
		case SA_LEVELUP:
			if(DIFF_TICK(sd->K_CHK_SA_LEVELUP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_LEVELUP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_LEVELUP >= (battle_config.WOE_K_DELAY_SA_LEVELUP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_LEVELUP >= (battle_config.K_DELAY_SA_LEVELUP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_LEVELUP = sd->K_LOCK_SA_LEVELUP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_LEVELUP = gettick() + battle_config.WOE_K_DELAY_SA_LEVELUP;
				else
					sd->K_CHK_SA_LEVELUP = gettick() + battle_config.K_DELAY_SA_LEVELUP;

				sd->K_LOCK_SA_LEVELUP = 0;
			}
			break;
		case SA_INSTANTDEATH:
			if(DIFF_TICK(sd->K_CHK_SA_INSTANTDEATH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_INSTANTDEATH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_INSTANTDEATH >= (battle_config.WOE_K_DELAY_SA_INSTANTDEATH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_INSTANTDEATH >= (battle_config.K_DELAY_SA_INSTANTDEATH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_INSTANTDEATH = sd->K_LOCK_SA_INSTANTDEATH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_INSTANTDEATH = gettick() + battle_config.WOE_K_DELAY_SA_INSTANTDEATH;
				else
					sd->K_CHK_SA_INSTANTDEATH = gettick() + battle_config.K_DELAY_SA_INSTANTDEATH;

				sd->K_LOCK_SA_INSTANTDEATH = 0;
			}
			break;
		case SA_FULLRECOVERY:
			if(DIFF_TICK(sd->K_CHK_SA_FULLRECOVERY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_FULLRECOVERY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_FULLRECOVERY >= (battle_config.WOE_K_DELAY_SA_FULLRECOVERY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_FULLRECOVERY >= (battle_config.K_DELAY_SA_FULLRECOVERY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_FULLRECOVERY = sd->K_LOCK_SA_FULLRECOVERY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_FULLRECOVERY = gettick() + battle_config.WOE_K_DELAY_SA_FULLRECOVERY;
				else
					sd->K_CHK_SA_FULLRECOVERY = gettick() + battle_config.K_DELAY_SA_FULLRECOVERY;

				sd->K_LOCK_SA_FULLRECOVERY = 0;
			}
			break;
		case SA_COMA:
			if(DIFF_TICK(sd->K_CHK_SA_COMA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SA_COMA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SA_COMA >= (battle_config.WOE_K_DELAY_SA_COMA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SA_COMA >= (battle_config.K_DELAY_SA_COMA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SA_COMA = sd->K_LOCK_SA_COMA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SA_COMA = gettick() + battle_config.WOE_K_DELAY_SA_COMA;
				else
					sd->K_CHK_SA_COMA = gettick() + battle_config.K_DELAY_SA_COMA;

				sd->K_LOCK_SA_COMA = 0;
			}
			break;
		case BD_ADAPTATION:
			if(DIFF_TICK(sd->K_CHK_BD_ADAPTATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BD_ADAPTATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BD_ADAPTATION >= (battle_config.WOE_K_DELAY_BD_ADAPTATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BD_ADAPTATION >= (battle_config.K_DELAY_BD_ADAPTATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BD_ADAPTATION = sd->K_LOCK_BD_ADAPTATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BD_ADAPTATION = gettick() + battle_config.WOE_K_DELAY_BD_ADAPTATION;
				else
					sd->K_CHK_BD_ADAPTATION = gettick() + battle_config.K_DELAY_BD_ADAPTATION;

				sd->K_LOCK_BD_ADAPTATION = 0;
			}
			break;
		case BD_ENCORE:
			if(DIFF_TICK(sd->K_CHK_BD_ENCORE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BD_ENCORE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BD_ENCORE >= (battle_config.WOE_K_DELAY_BD_ENCORE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BD_ENCORE >= (battle_config.K_DELAY_BD_ENCORE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BD_ENCORE = sd->K_LOCK_BD_ENCORE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BD_ENCORE = gettick() + battle_config.WOE_K_DELAY_BD_ENCORE;
				else
					sd->K_CHK_BD_ENCORE = gettick() + battle_config.K_DELAY_BD_ENCORE;

				sd->K_LOCK_BD_ENCORE = 0;
			}
			break;
		case BD_LULLABY:
			if(DIFF_TICK(sd->K_CHK_BD_LULLABY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BD_LULLABY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BD_LULLABY >= (battle_config.WOE_K_DELAY_BD_LULLABY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BD_LULLABY >= (battle_config.K_DELAY_BD_LULLABY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BD_LULLABY = sd->K_LOCK_BD_LULLABY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BD_LULLABY = gettick() + battle_config.WOE_K_DELAY_BD_LULLABY;
				else
					sd->K_CHK_BD_LULLABY = gettick() + battle_config.K_DELAY_BD_LULLABY;

				sd->K_LOCK_BD_LULLABY = 0;
			}
			break;
		case BD_RICHMANKIM:
			if(DIFF_TICK(sd->K_CHK_BD_RICHMANKIM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BD_RICHMANKIM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BD_RICHMANKIM >= (battle_config.WOE_K_DELAY_BD_RICHMANKIM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BD_RICHMANKIM >= (battle_config.K_DELAY_BD_RICHMANKIM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BD_RICHMANKIM = sd->K_LOCK_BD_RICHMANKIM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BD_RICHMANKIM = gettick() + battle_config.WOE_K_DELAY_BD_RICHMANKIM;
				else
					sd->K_CHK_BD_RICHMANKIM = gettick() + battle_config.K_DELAY_BD_RICHMANKIM;

				sd->K_LOCK_BD_RICHMANKIM = 0;
			}
			break;
		case BA_MUSICALSTRIKE:
			if(DIFF_TICK(sd->K_CHK_BA_MUSICALSTRIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_MUSICALSTRIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_MUSICALSTRIKE >= (battle_config.WOE_K_DELAY_BA_MUSICALSTRIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_MUSICALSTRIKE >= (battle_config.K_DELAY_BA_MUSICALSTRIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_MUSICALSTRIKE = sd->K_LOCK_BA_MUSICALSTRIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_MUSICALSTRIKE = gettick() + battle_config.WOE_K_DELAY_BA_MUSICALSTRIKE;
				else
					sd->K_CHK_BA_MUSICALSTRIKE = gettick() + battle_config.K_DELAY_BA_MUSICALSTRIKE;

				sd->K_LOCK_BA_MUSICALSTRIKE = 0;
			}
			break;
		case BA_DISSONANCE:
			if(DIFF_TICK(sd->K_CHK_BA_DISSONANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_DISSONANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_DISSONANCE >= (battle_config.WOE_K_DELAY_BA_DISSONANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_DISSONANCE >= (battle_config.K_DELAY_BA_DISSONANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_DISSONANCE = sd->K_LOCK_BA_DISSONANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_DISSONANCE = gettick() + battle_config.WOE_K_DELAY_BA_DISSONANCE;
				else
					sd->K_CHK_BA_DISSONANCE = gettick() + battle_config.K_DELAY_BA_DISSONANCE;

				sd->K_LOCK_BA_DISSONANCE = 0;
			}
			break;
		case BA_FROSTJOKER:
			if(DIFF_TICK(sd->K_CHK_BA_FROSTJOKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_FROSTJOKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_FROSTJOKER >= (battle_config.WOE_K_DELAY_BA_FROSTJOKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_FROSTJOKER >= (battle_config.K_DELAY_BA_FROSTJOKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_FROSTJOKER = sd->K_LOCK_BA_FROSTJOKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_FROSTJOKER = gettick() + battle_config.WOE_K_DELAY_BA_FROSTJOKER;
				else
					sd->K_CHK_BA_FROSTJOKER = gettick() + battle_config.K_DELAY_BA_FROSTJOKER;

				sd->K_LOCK_BA_FROSTJOKER = 0;
			}
			break;
		case BA_WHISTLE:
			if(DIFF_TICK(sd->K_CHK_BA_WHISTLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_WHISTLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_WHISTLE >= (battle_config.WOE_K_DELAY_BA_WHISTLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_WHISTLE >= (battle_config.K_DELAY_BA_WHISTLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_WHISTLE = sd->K_LOCK_BA_WHISTLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_WHISTLE = gettick() + battle_config.WOE_K_DELAY_BA_WHISTLE;
				else
					sd->K_CHK_BA_WHISTLE = gettick() + battle_config.K_DELAY_BA_WHISTLE;

				sd->K_LOCK_BA_WHISTLE = 0;
			}
			break;
		case BA_ASSASSINCROSS:
			if(DIFF_TICK(sd->K_CHK_BA_ASSASSINCROSS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_ASSASSINCROSS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_ASSASSINCROSS >= (battle_config.WOE_K_DELAY_BA_ASSASSINCROSS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_ASSASSINCROSS >= (battle_config.K_DELAY_BA_ASSASSINCROSS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_ASSASSINCROSS = sd->K_LOCK_BA_ASSASSINCROSS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_ASSASSINCROSS = gettick() + battle_config.WOE_K_DELAY_BA_ASSASSINCROSS;
				else
					sd->K_CHK_BA_ASSASSINCROSS = gettick() + battle_config.K_DELAY_BA_ASSASSINCROSS;

				sd->K_LOCK_BA_ASSASSINCROSS = 0;
			}
			break;
		case BA_POEMBRAGI:
			if(DIFF_TICK(sd->K_CHK_BA_POEMBRAGI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_POEMBRAGI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_POEMBRAGI >= (battle_config.WOE_K_DELAY_BA_POEMBRAGI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_POEMBRAGI >= (battle_config.K_DELAY_BA_POEMBRAGI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_POEMBRAGI = sd->K_LOCK_BA_POEMBRAGI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_POEMBRAGI = gettick() + battle_config.WOE_K_DELAY_BA_POEMBRAGI;
				else
					sd->K_CHK_BA_POEMBRAGI = gettick() + battle_config.K_DELAY_BA_POEMBRAGI;

				sd->K_LOCK_BA_POEMBRAGI = 0;
			}
			break;
		case BA_APPLEIDUN:
			if(DIFF_TICK(sd->K_CHK_BA_APPLEIDUN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_APPLEIDUN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_APPLEIDUN >= (battle_config.WOE_K_DELAY_BA_APPLEIDUN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_APPLEIDUN >= (battle_config.K_DELAY_BA_APPLEIDUN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_APPLEIDUN = sd->K_LOCK_BA_APPLEIDUN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_APPLEIDUN = gettick() + battle_config.WOE_K_DELAY_BA_APPLEIDUN;
				else
					sd->K_CHK_BA_APPLEIDUN = gettick() + battle_config.K_DELAY_BA_APPLEIDUN;

				sd->K_LOCK_BA_APPLEIDUN = 0;
			}
			break;
		case DC_THROWARROW:
			if(DIFF_TICK(sd->K_CHK_DC_THROWARROW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_THROWARROW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_THROWARROW >= (battle_config.WOE_K_DELAY_DC_THROWARROW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_THROWARROW >= (battle_config.K_DELAY_DC_THROWARROW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_THROWARROW = sd->K_LOCK_DC_THROWARROW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_THROWARROW = gettick() + battle_config.WOE_K_DELAY_DC_THROWARROW;
				else
					sd->K_CHK_DC_THROWARROW = gettick() + battle_config.K_DELAY_DC_THROWARROW;

				sd->K_LOCK_DC_THROWARROW = 0;
			}
			break;
		case DC_UGLYDANCE:
			if(DIFF_TICK(sd->K_CHK_DC_UGLYDANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_UGLYDANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_UGLYDANCE >= (battle_config.WOE_K_DELAY_DC_UGLYDANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_UGLYDANCE >= (battle_config.K_DELAY_DC_UGLYDANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_UGLYDANCE = sd->K_LOCK_DC_UGLYDANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_UGLYDANCE = gettick() + battle_config.WOE_K_DELAY_DC_UGLYDANCE;
				else
					sd->K_CHK_DC_UGLYDANCE = gettick() + battle_config.K_DELAY_DC_UGLYDANCE;

				sd->K_LOCK_DC_UGLYDANCE = 0;
			}
			break;
		case DC_SCREAM:
			if(DIFF_TICK(sd->K_CHK_DC_SCREAM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_SCREAM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_SCREAM >= (battle_config.WOE_K_DELAY_DC_SCREAM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_SCREAM >= (battle_config.K_DELAY_DC_SCREAM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_SCREAM = sd->K_LOCK_DC_SCREAM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_SCREAM = gettick() + battle_config.WOE_K_DELAY_DC_SCREAM;
				else
					sd->K_CHK_DC_SCREAM = gettick() + battle_config.K_DELAY_DC_SCREAM;

				sd->K_LOCK_DC_SCREAM = 0;
			}
			break;
		case DC_HUMMING:
			if(DIFF_TICK(sd->K_CHK_DC_HUMMING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_HUMMING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_HUMMING >= (battle_config.WOE_K_DELAY_DC_HUMMING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_HUMMING >= (battle_config.K_DELAY_DC_HUMMING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_HUMMING = sd->K_LOCK_DC_HUMMING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_HUMMING = gettick() + battle_config.WOE_K_DELAY_DC_HUMMING;
				else
					sd->K_CHK_DC_HUMMING = gettick() + battle_config.K_DELAY_DC_HUMMING;

				sd->K_LOCK_DC_HUMMING = 0;
			}
			break;
		case DC_DONTFORGETME:
			if(DIFF_TICK(sd->K_CHK_DC_DONTFORGETME,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_DONTFORGETME - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_DONTFORGETME >= (battle_config.WOE_K_DELAY_DC_DONTFORGETME/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_DONTFORGETME >= (battle_config.K_DELAY_DC_DONTFORGETME/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_DONTFORGETME = sd->K_LOCK_DC_DONTFORGETME +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_DONTFORGETME = gettick() + battle_config.WOE_K_DELAY_DC_DONTFORGETME;
				else
					sd->K_CHK_DC_DONTFORGETME = gettick() + battle_config.K_DELAY_DC_DONTFORGETME;

				sd->K_LOCK_DC_DONTFORGETME = 0;
			}
			break;
		case DC_FORTUNEKISS:
			if(DIFF_TICK(sd->K_CHK_DC_FORTUNEKISS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_FORTUNEKISS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_FORTUNEKISS >= (battle_config.WOE_K_DELAY_DC_FORTUNEKISS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_FORTUNEKISS >= (battle_config.K_DELAY_DC_FORTUNEKISS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_FORTUNEKISS = sd->K_LOCK_DC_FORTUNEKISS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_FORTUNEKISS = gettick() + battle_config.WOE_K_DELAY_DC_FORTUNEKISS;
				else
					sd->K_CHK_DC_FORTUNEKISS = gettick() + battle_config.K_DELAY_DC_FORTUNEKISS;

				sd->K_LOCK_DC_FORTUNEKISS = 0;
			}
			break;
		case DC_SERVICEFORYOU:
			if(DIFF_TICK(sd->K_CHK_DC_SERVICEFORYOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_SERVICEFORYOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_SERVICEFORYOU >= (battle_config.WOE_K_DELAY_DC_SERVICEFORYOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_SERVICEFORYOU >= (battle_config.K_DELAY_DC_SERVICEFORYOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_SERVICEFORYOU = sd->K_LOCK_DC_SERVICEFORYOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_SERVICEFORYOU = gettick() + battle_config.WOE_K_DELAY_DC_SERVICEFORYOU;
				else
					sd->K_CHK_DC_SERVICEFORYOU = gettick() + battle_config.K_DELAY_DC_SERVICEFORYOU;

				sd->K_LOCK_DC_SERVICEFORYOU = 0;
			}
			break;
		case LK_FURY:
			if(DIFF_TICK(sd->K_CHK_LK_FURY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LK_FURY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LK_FURY >= (battle_config.WOE_K_DELAY_LK_FURY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LK_FURY >= (battle_config.K_DELAY_LK_FURY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LK_FURY = sd->K_LOCK_LK_FURY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LK_FURY = gettick() + battle_config.WOE_K_DELAY_LK_FURY;
				else
					sd->K_CHK_LK_FURY = gettick() + battle_config.K_DELAY_LK_FURY;

				sd->K_LOCK_LK_FURY = 0;
			}
			break;
		case HW_MAGICCRASHER:
			if(DIFF_TICK(sd->K_CHK_HW_MAGICCRASHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HW_MAGICCRASHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HW_MAGICCRASHER >= (battle_config.WOE_K_DELAY_HW_MAGICCRASHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HW_MAGICCRASHER >= (battle_config.K_DELAY_HW_MAGICCRASHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HW_MAGICCRASHER = sd->K_LOCK_HW_MAGICCRASHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HW_MAGICCRASHER = gettick() + battle_config.WOE_K_DELAY_HW_MAGICCRASHER;
				else
					sd->K_CHK_HW_MAGICCRASHER = gettick() + battle_config.K_DELAY_HW_MAGICCRASHER;

				sd->K_LOCK_HW_MAGICCRASHER = 0;
			}
			break;
		case PA_PRESSURE:
			if(DIFF_TICK(sd->K_CHK_PA_PRESSURE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PA_PRESSURE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PA_PRESSURE >= (battle_config.WOE_K_DELAY_PA_PRESSURE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PA_PRESSURE >= (battle_config.K_DELAY_PA_PRESSURE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PA_PRESSURE = sd->K_LOCK_PA_PRESSURE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PA_PRESSURE = gettick() + battle_config.WOE_K_DELAY_PA_PRESSURE;
				else
					sd->K_CHK_PA_PRESSURE = gettick() + battle_config.K_DELAY_PA_PRESSURE;

				sd->K_LOCK_PA_PRESSURE = 0;
			}
			break;
		case CH_PALMSTRIKE:
			if(DIFF_TICK(sd->K_CHK_CH_PALMSTRIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CH_PALMSTRIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CH_PALMSTRIKE >= (battle_config.WOE_K_DELAY_CH_PALMSTRIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CH_PALMSTRIKE >= (battle_config.K_DELAY_CH_PALMSTRIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CH_PALMSTRIKE = sd->K_LOCK_CH_PALMSTRIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CH_PALMSTRIKE = gettick() + battle_config.WOE_K_DELAY_CH_PALMSTRIKE;
				else
					sd->K_CHK_CH_PALMSTRIKE = gettick() + battle_config.K_DELAY_CH_PALMSTRIKE;

				sd->K_LOCK_CH_PALMSTRIKE = 0;
			}
			break;
		case CH_TIGERFIST:
			if(DIFF_TICK(sd->K_CHK_CH_TIGERFIST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CH_TIGERFIST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CH_TIGERFIST >= (battle_config.WOE_K_DELAY_CH_TIGERFIST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CH_TIGERFIST >= (battle_config.K_DELAY_CH_TIGERFIST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CH_TIGERFIST = sd->K_LOCK_CH_TIGERFIST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CH_TIGERFIST = gettick() + battle_config.WOE_K_DELAY_CH_TIGERFIST;
				else
					sd->K_CHK_CH_TIGERFIST = gettick() + battle_config.K_DELAY_CH_TIGERFIST;

				sd->K_LOCK_CH_TIGERFIST = 0;
			}
			break;
		case CH_CHAINCRUSH:
			if(DIFF_TICK(sd->K_CHK_CH_CHAINCRUSH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CH_CHAINCRUSH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CH_CHAINCRUSH >= (battle_config.WOE_K_DELAY_CH_CHAINCRUSH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CH_CHAINCRUSH >= (battle_config.K_DELAY_CH_CHAINCRUSH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CH_CHAINCRUSH = sd->K_LOCK_CH_CHAINCRUSH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CH_CHAINCRUSH = gettick() + battle_config.WOE_K_DELAY_CH_CHAINCRUSH;
				else
					sd->K_CHK_CH_CHAINCRUSH = gettick() + battle_config.K_DELAY_CH_CHAINCRUSH;

				sd->K_LOCK_CH_CHAINCRUSH = 0;
			}
			break;
		case PF_SOULCHANGE:
			if(DIFF_TICK(sd->K_CHK_PF_SOULCHANGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PF_SOULCHANGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PF_SOULCHANGE >= (battle_config.WOE_K_DELAY_PF_SOULCHANGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PF_SOULCHANGE >= (battle_config.K_DELAY_PF_SOULCHANGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PF_SOULCHANGE = sd->K_LOCK_PF_SOULCHANGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PF_SOULCHANGE = gettick() + battle_config.WOE_K_DELAY_PF_SOULCHANGE;
				else
					sd->K_CHK_PF_SOULCHANGE = gettick() + battle_config.K_DELAY_PF_SOULCHANGE;

				sd->K_LOCK_PF_SOULCHANGE = 0;
			}
			break;
		case PF_SOULBURN:
			if(DIFF_TICK(sd->K_CHK_PF_SOULBURN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PF_SOULBURN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PF_SOULBURN >= (battle_config.WOE_K_DELAY_PF_SOULBURN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PF_SOULBURN >= (battle_config.K_DELAY_PF_SOULBURN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PF_SOULBURN = sd->K_LOCK_PF_SOULBURN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PF_SOULBURN = gettick() + battle_config.WOE_K_DELAY_PF_SOULBURN;
				else
					sd->K_CHK_PF_SOULBURN = gettick() + battle_config.K_DELAY_PF_SOULBURN;

				sd->K_LOCK_PF_SOULBURN = 0;
			}
			break;
		case ASC_BREAKER:
			if(DIFF_TICK(sd->K_CHK_ASC_BREAKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_ASC_BREAKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_ASC_BREAKER >= (battle_config.WOE_K_DELAY_ASC_BREAKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_ASC_BREAKER >= (battle_config.K_DELAY_ASC_BREAKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_ASC_BREAKER = sd->K_LOCK_ASC_BREAKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_ASC_BREAKER = gettick() + battle_config.WOE_K_DELAY_ASC_BREAKER;
				else
					sd->K_CHK_ASC_BREAKER = gettick() + battle_config.K_DELAY_ASC_BREAKER;

				sd->K_LOCK_ASC_BREAKER = 0;
			}
			break;
		case SN_FALCONASSAULT:
			if(DIFF_TICK(sd->K_CHK_SN_FALCONASSAULT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SN_FALCONASSAULT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SN_FALCONASSAULT >= (battle_config.WOE_K_DELAY_SN_FALCONASSAULT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SN_FALCONASSAULT >= (battle_config.K_DELAY_SN_FALCONASSAULT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SN_FALCONASSAULT = sd->K_LOCK_SN_FALCONASSAULT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SN_FALCONASSAULT = gettick() + battle_config.WOE_K_DELAY_SN_FALCONASSAULT;
				else
					sd->K_CHK_SN_FALCONASSAULT = gettick() + battle_config.K_DELAY_SN_FALCONASSAULT;

				sd->K_LOCK_SN_FALCONASSAULT = 0;
			}
			break;
		case SN_SHARPSHOOTING:
			if(DIFF_TICK(sd->K_CHK_SN_SHARPSHOOTING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SN_SHARPSHOOTING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SN_SHARPSHOOTING >= (battle_config.WOE_K_DELAY_SN_SHARPSHOOTING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SN_SHARPSHOOTING >= (battle_config.K_DELAY_SN_SHARPSHOOTING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SN_SHARPSHOOTING = sd->K_LOCK_SN_SHARPSHOOTING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SN_SHARPSHOOTING = gettick() + battle_config.WOE_K_DELAY_SN_SHARPSHOOTING;
				else
					sd->K_CHK_SN_SHARPSHOOTING = gettick() + battle_config.K_DELAY_SN_SHARPSHOOTING;

				sd->K_LOCK_SN_SHARPSHOOTING = 0;
			}
			break;
		case CR_ALCHEMY:
			if(DIFF_TICK(sd->K_CHK_CR_ALCHEMY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_ALCHEMY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_ALCHEMY >= (battle_config.WOE_K_DELAY_CR_ALCHEMY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_ALCHEMY >= (battle_config.K_DELAY_CR_ALCHEMY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_ALCHEMY = sd->K_LOCK_CR_ALCHEMY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_ALCHEMY = gettick() + battle_config.WOE_K_DELAY_CR_ALCHEMY;
				else
					sd->K_CHK_CR_ALCHEMY = gettick() + battle_config.K_DELAY_CR_ALCHEMY;

				sd->K_LOCK_CR_ALCHEMY = 0;
			}
			break;
		case CR_SYNTHESISPOTION:
			if(DIFF_TICK(sd->K_CHK_CR_SYNTHESISPOTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_SYNTHESISPOTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_SYNTHESISPOTION >= (battle_config.WOE_K_DELAY_CR_SYNTHESISPOTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_SYNTHESISPOTION >= (battle_config.K_DELAY_CR_SYNTHESISPOTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_SYNTHESISPOTION = sd->K_LOCK_CR_SYNTHESISPOTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_SYNTHESISPOTION = gettick() + battle_config.WOE_K_DELAY_CR_SYNTHESISPOTION;
				else
					sd->K_CHK_CR_SYNTHESISPOTION = gettick() + battle_config.K_DELAY_CR_SYNTHESISPOTION;

				sd->K_LOCK_CR_SYNTHESISPOTION = 0;
			}
			break;
		case CG_ARROWVULCAN:
			if(DIFF_TICK(sd->K_CHK_CG_ARROWVULCAN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CG_ARROWVULCAN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CG_ARROWVULCAN >= (battle_config.WOE_K_DELAY_CG_ARROWVULCAN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CG_ARROWVULCAN >= (battle_config.K_DELAY_CG_ARROWVULCAN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CG_ARROWVULCAN = sd->K_LOCK_CG_ARROWVULCAN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CG_ARROWVULCAN = gettick() + battle_config.WOE_K_DELAY_CG_ARROWVULCAN;
				else
					sd->K_CHK_CG_ARROWVULCAN = gettick() + battle_config.K_DELAY_CG_ARROWVULCAN;

				sd->K_LOCK_CG_ARROWVULCAN = 0;
			}
			break;
		case CG_MOONLIT:
			if(DIFF_TICK(sd->K_CHK_CG_MOONLIT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CG_MOONLIT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CG_MOONLIT >= (battle_config.WOE_K_DELAY_CG_MOONLIT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CG_MOONLIT >= (battle_config.K_DELAY_CG_MOONLIT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CG_MOONLIT = sd->K_LOCK_CG_MOONLIT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CG_MOONLIT = gettick() + battle_config.WOE_K_DELAY_CG_MOONLIT;
				else
					sd->K_CHK_CG_MOONLIT = gettick() + battle_config.K_DELAY_CG_MOONLIT;

				sd->K_LOCK_CG_MOONLIT = 0;
			}
			break;
		case CG_MARIONETTE:
			if(DIFF_TICK(sd->K_CHK_CG_MARIONETTE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CG_MARIONETTE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CG_MARIONETTE >= (battle_config.WOE_K_DELAY_CG_MARIONETTE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CG_MARIONETTE >= (battle_config.K_DELAY_CG_MARIONETTE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CG_MARIONETTE = sd->K_LOCK_CG_MARIONETTE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CG_MARIONETTE = gettick() + battle_config.WOE_K_DELAY_CG_MARIONETTE;
				else
					sd->K_CHK_CG_MARIONETTE = gettick() + battle_config.K_DELAY_CG_MARIONETTE;

				sd->K_LOCK_CG_MARIONETTE = 0;
			}
			break;
		case LK_SPIRALPIERCE:
			if(DIFF_TICK(sd->K_CHK_LK_SPIRALPIERCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LK_SPIRALPIERCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LK_SPIRALPIERCE >= (battle_config.WOE_K_DELAY_LK_SPIRALPIERCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LK_SPIRALPIERCE >= (battle_config.K_DELAY_LK_SPIRALPIERCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LK_SPIRALPIERCE = sd->K_LOCK_LK_SPIRALPIERCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LK_SPIRALPIERCE = gettick() + battle_config.WOE_K_DELAY_LK_SPIRALPIERCE;
				else
					sd->K_CHK_LK_SPIRALPIERCE = gettick() + battle_config.K_DELAY_LK_SPIRALPIERCE;

				sd->K_LOCK_LK_SPIRALPIERCE = 0;
			}
			break;
		case LK_HEADCRUSH:
			if(DIFF_TICK(sd->K_CHK_LK_HEADCRUSH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LK_HEADCRUSH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LK_HEADCRUSH >= (battle_config.WOE_K_DELAY_LK_HEADCRUSH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LK_HEADCRUSH >= (battle_config.K_DELAY_LK_HEADCRUSH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LK_HEADCRUSH = sd->K_LOCK_LK_HEADCRUSH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LK_HEADCRUSH = gettick() + battle_config.WOE_K_DELAY_LK_HEADCRUSH;
				else
					sd->K_CHK_LK_HEADCRUSH = gettick() + battle_config.K_DELAY_LK_HEADCRUSH;

				sd->K_LOCK_LK_HEADCRUSH = 0;
			}
			break;
		case LK_JOINTBEAT:
			if(DIFF_TICK(sd->K_CHK_LK_JOINTBEAT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LK_JOINTBEAT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LK_JOINTBEAT >= (battle_config.WOE_K_DELAY_LK_JOINTBEAT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LK_JOINTBEAT >= (battle_config.K_DELAY_LK_JOINTBEAT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LK_JOINTBEAT = sd->K_LOCK_LK_JOINTBEAT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LK_JOINTBEAT = gettick() + battle_config.WOE_K_DELAY_LK_JOINTBEAT;
				else
					sd->K_CHK_LK_JOINTBEAT = gettick() + battle_config.K_DELAY_LK_JOINTBEAT;

				sd->K_LOCK_LK_JOINTBEAT = 0;
			}
			break;
		case HW_NAPALMVULCAN:
			if(DIFF_TICK(sd->K_CHK_HW_NAPALMVULCAN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HW_NAPALMVULCAN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HW_NAPALMVULCAN >= (battle_config.WOE_K_DELAY_HW_NAPALMVULCAN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HW_NAPALMVULCAN >= (battle_config.K_DELAY_HW_NAPALMVULCAN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HW_NAPALMVULCAN = sd->K_LOCK_HW_NAPALMVULCAN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HW_NAPALMVULCAN = gettick() + battle_config.WOE_K_DELAY_HW_NAPALMVULCAN;
				else
					sd->K_CHK_HW_NAPALMVULCAN = gettick() + battle_config.K_DELAY_HW_NAPALMVULCAN;

				sd->K_LOCK_HW_NAPALMVULCAN = 0;
			}
			break;
		case CH_SOULCOLLECT:
			if(DIFF_TICK(sd->K_CHK_CH_SOULCOLLECT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CH_SOULCOLLECT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CH_SOULCOLLECT >= (battle_config.WOE_K_DELAY_CH_SOULCOLLECT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CH_SOULCOLLECT >= (battle_config.K_DELAY_CH_SOULCOLLECT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CH_SOULCOLLECT = sd->K_LOCK_CH_SOULCOLLECT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CH_SOULCOLLECT = gettick() + battle_config.WOE_K_DELAY_CH_SOULCOLLECT;
				else
					sd->K_CHK_CH_SOULCOLLECT = gettick() + battle_config.K_DELAY_CH_SOULCOLLECT;

				sd->K_LOCK_CH_SOULCOLLECT = 0;
			}
			break;
		case PF_MINDBREAKER:
			if(DIFF_TICK(sd->K_CHK_PF_MINDBREAKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PF_MINDBREAKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PF_MINDBREAKER >= (battle_config.WOE_K_DELAY_PF_MINDBREAKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PF_MINDBREAKER >= (battle_config.K_DELAY_PF_MINDBREAKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PF_MINDBREAKER = sd->K_LOCK_PF_MINDBREAKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PF_MINDBREAKER = gettick() + battle_config.WOE_K_DELAY_PF_MINDBREAKER;
				else
					sd->K_CHK_PF_MINDBREAKER = gettick() + battle_config.K_DELAY_PF_MINDBREAKER;

				sd->K_LOCK_PF_MINDBREAKER = 0;
			}
			break;
		case PF_SPIDERWEB:
			if(DIFF_TICK(sd->K_CHK_PF_SPIDERWEB,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PF_SPIDERWEB - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PF_SPIDERWEB >= (battle_config.WOE_K_DELAY_PF_SPIDERWEB/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PF_SPIDERWEB >= (battle_config.K_DELAY_PF_SPIDERWEB/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PF_SPIDERWEB = sd->K_LOCK_PF_SPIDERWEB +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PF_SPIDERWEB = gettick() + battle_config.WOE_K_DELAY_PF_SPIDERWEB;
				else
					sd->K_CHK_PF_SPIDERWEB = gettick() + battle_config.K_DELAY_PF_SPIDERWEB;

				sd->K_LOCK_PF_SPIDERWEB = 0;
			}
			break;
		case ASC_METEORASSAULT:
			if(DIFF_TICK(sd->K_CHK_ASC_METEORASSAULT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_ASC_METEORASSAULT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_ASC_METEORASSAULT >= (battle_config.WOE_K_DELAY_ASC_METEORASSAULT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_ASC_METEORASSAULT >= (battle_config.K_DELAY_ASC_METEORASSAULT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_ASC_METEORASSAULT = sd->K_LOCK_ASC_METEORASSAULT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_ASC_METEORASSAULT = gettick() + battle_config.WOE_K_DELAY_ASC_METEORASSAULT;
				else
					sd->K_CHK_ASC_METEORASSAULT = gettick() + battle_config.K_DELAY_ASC_METEORASSAULT;

				sd->K_LOCK_ASC_METEORASSAULT = 0;
			}
			break;
		case TK_STORMKICK:
			if(DIFF_TICK(sd->K_CHK_TK_STORMKICK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_STORMKICK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_STORMKICK >= (battle_config.WOE_K_DELAY_TK_STORMKICK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_STORMKICK >= (battle_config.K_DELAY_TK_STORMKICK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_STORMKICK = sd->K_LOCK_TK_STORMKICK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_STORMKICK = gettick() + battle_config.WOE_K_DELAY_TK_STORMKICK;
				else
					sd->K_CHK_TK_STORMKICK = gettick() + battle_config.K_DELAY_TK_STORMKICK;

				sd->K_LOCK_TK_STORMKICK = 0;
			}
			break;
		case TK_DOWNKICK:
			if(DIFF_TICK(sd->K_CHK_TK_DOWNKICK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_DOWNKICK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_DOWNKICK >= (battle_config.WOE_K_DELAY_TK_DOWNKICK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_DOWNKICK >= (battle_config.K_DELAY_TK_DOWNKICK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_DOWNKICK = sd->K_LOCK_TK_DOWNKICK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_DOWNKICK = gettick() + battle_config.WOE_K_DELAY_TK_DOWNKICK;
				else
					sd->K_CHK_TK_DOWNKICK = gettick() + battle_config.K_DELAY_TK_DOWNKICK;

				sd->K_LOCK_TK_DOWNKICK = 0;
			}
			break;
		case TK_TURNKICK:
			if(DIFF_TICK(sd->K_CHK_TK_TURNKICK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_TURNKICK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_TURNKICK >= (battle_config.WOE_K_DELAY_TK_TURNKICK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_TURNKICK >= (battle_config.K_DELAY_TK_TURNKICK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_TURNKICK = sd->K_LOCK_TK_TURNKICK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_TURNKICK = gettick() + battle_config.WOE_K_DELAY_TK_TURNKICK;
				else
					sd->K_CHK_TK_TURNKICK = gettick() + battle_config.K_DELAY_TK_TURNKICK;

				sd->K_LOCK_TK_TURNKICK = 0;
			}
			break;
		case TK_JUMPKICK:
			if(DIFF_TICK(sd->K_CHK_TK_JUMPKICK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_JUMPKICK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_JUMPKICK >= (battle_config.WOE_K_DELAY_TK_JUMPKICK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_JUMPKICK >= (battle_config.K_DELAY_TK_JUMPKICK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_JUMPKICK = sd->K_LOCK_TK_JUMPKICK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_JUMPKICK = gettick() + battle_config.WOE_K_DELAY_TK_JUMPKICK;
				else
					sd->K_CHK_TK_JUMPKICK = gettick() + battle_config.K_DELAY_TK_JUMPKICK;

				sd->K_LOCK_TK_JUMPKICK = 0;
			}
			break;
		case TK_POWER:
			if(DIFF_TICK(sd->K_CHK_TK_POWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_POWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_POWER >= (battle_config.WOE_K_DELAY_TK_POWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_POWER >= (battle_config.K_DELAY_TK_POWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_POWER = sd->K_LOCK_TK_POWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_POWER = gettick() + battle_config.WOE_K_DELAY_TK_POWER;
				else
					sd->K_CHK_TK_POWER = gettick() + battle_config.K_DELAY_TK_POWER;

				sd->K_LOCK_TK_POWER = 0;
			}
			break;
		case TK_HIGHJUMP:
			if(DIFF_TICK(sd->K_CHK_TK_HIGHJUMP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_TK_HIGHJUMP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_TK_HIGHJUMP >= (battle_config.WOE_K_DELAY_TK_HIGHJUMP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_TK_HIGHJUMP >= (battle_config.K_DELAY_TK_HIGHJUMP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_TK_HIGHJUMP = sd->K_LOCK_TK_HIGHJUMP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_TK_HIGHJUMP = gettick() + battle_config.WOE_K_DELAY_TK_HIGHJUMP;
				else
					sd->K_CHK_TK_HIGHJUMP = gettick() + battle_config.K_DELAY_TK_HIGHJUMP;

				sd->K_LOCK_TK_HIGHJUMP = 0;
			}
			break;
		case SL_KAIZEL:
			if(DIFF_TICK(sd->K_CHK_SL_KAIZEL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_KAIZEL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_KAIZEL >= (battle_config.WOE_K_DELAY_SL_KAIZEL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_KAIZEL >= (battle_config.K_DELAY_SL_KAIZEL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_KAIZEL = sd->K_LOCK_SL_KAIZEL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_KAIZEL = gettick() + battle_config.WOE_K_DELAY_SL_KAIZEL;
				else
					sd->K_CHK_SL_KAIZEL = gettick() + battle_config.K_DELAY_SL_KAIZEL;

				sd->K_LOCK_SL_KAIZEL = 0;
			}
			break;
		case SL_KAAHI:
			if(DIFF_TICK(sd->K_CHK_SL_KAAHI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_KAAHI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_KAAHI >= (battle_config.WOE_K_DELAY_SL_KAAHI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_KAAHI >= (battle_config.K_DELAY_SL_KAAHI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_KAAHI = sd->K_LOCK_SL_KAAHI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_KAAHI = gettick() + battle_config.WOE_K_DELAY_SL_KAAHI;
				else
					sd->K_CHK_SL_KAAHI = gettick() + battle_config.K_DELAY_SL_KAAHI;

				sd->K_LOCK_SL_KAAHI = 0;
			}
			break;
		case SL_KAUPE:
			if(DIFF_TICK(sd->K_CHK_SL_KAUPE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_KAUPE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_KAUPE >= (battle_config.WOE_K_DELAY_SL_KAUPE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_KAUPE >= (battle_config.K_DELAY_SL_KAUPE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_KAUPE = sd->K_LOCK_SL_KAUPE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_KAUPE = gettick() + battle_config.WOE_K_DELAY_SL_KAUPE;
				else
					sd->K_CHK_SL_KAUPE = gettick() + battle_config.K_DELAY_SL_KAUPE;

				sd->K_LOCK_SL_KAUPE = 0;
			}
			break;
		case SL_KAITE:
			if(DIFF_TICK(sd->K_CHK_SL_KAITE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_KAITE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_KAITE >= (battle_config.WOE_K_DELAY_SL_KAITE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_KAITE >= (battle_config.K_DELAY_SL_KAITE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_KAITE = sd->K_LOCK_SL_KAITE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_KAITE = gettick() + battle_config.WOE_K_DELAY_SL_KAITE;
				else
					sd->K_CHK_SL_KAITE = gettick() + battle_config.K_DELAY_SL_KAITE;

				sd->K_LOCK_SL_KAITE = 0;
			}
			break;
		case SL_KAINA:
			if(DIFF_TICK(sd->K_CHK_SL_KAINA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_KAINA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_KAINA >= (battle_config.WOE_K_DELAY_SL_KAINA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_KAINA >= (battle_config.K_DELAY_SL_KAINA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_KAINA = sd->K_LOCK_SL_KAINA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_KAINA = gettick() + battle_config.WOE_K_DELAY_SL_KAINA;
				else
					sd->K_CHK_SL_KAINA = gettick() + battle_config.K_DELAY_SL_KAINA;

				sd->K_LOCK_SL_KAINA = 0;
			}
			break;
		case SL_STIN:
			if(DIFF_TICK(sd->K_CHK_SL_STIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_STIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_STIN >= (battle_config.WOE_K_DELAY_SL_STIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_STIN >= (battle_config.K_DELAY_SL_STIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_STIN = sd->K_LOCK_SL_STIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_STIN = gettick() + battle_config.WOE_K_DELAY_SL_STIN;
				else
					sd->K_CHK_SL_STIN = gettick() + battle_config.K_DELAY_SL_STIN;

				sd->K_LOCK_SL_STIN = 0;
			}
			break;
		case SL_STUN:
			if(DIFF_TICK(sd->K_CHK_SL_STUN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_STUN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_STUN >= (battle_config.WOE_K_DELAY_SL_STUN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_STUN >= (battle_config.K_DELAY_SL_STUN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_STUN = sd->K_LOCK_SL_STUN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_STUN = gettick() + battle_config.WOE_K_DELAY_SL_STUN;
				else
					sd->K_CHK_SL_STUN = gettick() + battle_config.K_DELAY_SL_STUN;

				sd->K_LOCK_SL_STUN = 0;
			}
			break;
		case SL_SMA:
			if(DIFF_TICK(sd->K_CHK_SL_SMA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_SMA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_SMA >= (battle_config.WOE_K_DELAY_SL_SMA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_SMA >= (battle_config.K_DELAY_SL_SMA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_SMA = sd->K_LOCK_SL_SMA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_SMA = gettick() + battle_config.WOE_K_DELAY_SL_SMA;
				else
					sd->K_CHK_SL_SMA = gettick() + battle_config.K_DELAY_SL_SMA;

				sd->K_LOCK_SL_SMA = 0;
			}
			break;
		case SL_SWOO:
			if(DIFF_TICK(sd->K_CHK_SL_SWOO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_SWOO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_SWOO >= (battle_config.WOE_K_DELAY_SL_SWOO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_SWOO >= (battle_config.K_DELAY_SL_SWOO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_SWOO = sd->K_LOCK_SL_SWOO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_SWOO = gettick() + battle_config.WOE_K_DELAY_SL_SWOO;
				else
					sd->K_CHK_SL_SWOO = gettick() + battle_config.K_DELAY_SL_SWOO;

				sd->K_LOCK_SL_SWOO = 0;
			}
			break;
		case SL_SKE:
			if(DIFF_TICK(sd->K_CHK_SL_SKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_SKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_SKE >= (battle_config.WOE_K_DELAY_SL_SKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_SKE >= (battle_config.K_DELAY_SL_SKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_SKE = sd->K_LOCK_SL_SKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_SKE = gettick() + battle_config.WOE_K_DELAY_SL_SKE;
				else
					sd->K_CHK_SL_SKE = gettick() + battle_config.K_DELAY_SL_SKE;

				sd->K_LOCK_SL_SKE = 0;
			}
			break;
		case SL_SKA:
			if(DIFF_TICK(sd->K_CHK_SL_SKA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_SKA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_SKA >= (battle_config.WOE_K_DELAY_SL_SKA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_SKA >= (battle_config.K_DELAY_SL_SKA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_SKA = sd->K_LOCK_SL_SKA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_SKA = gettick() + battle_config.WOE_K_DELAY_SL_SKA;
				else
					sd->K_CHK_SL_SKA = gettick() + battle_config.K_DELAY_SL_SKA;

				sd->K_LOCK_SL_SKA = 0;
			}
			break;
		case ST_FULLSTRIP:
			if(DIFF_TICK(sd->K_CHK_ST_FULLSTRIP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_ST_FULLSTRIP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_ST_FULLSTRIP >= (battle_config.WOE_K_DELAY_ST_FULLSTRIP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_ST_FULLSTRIP >= (battle_config.K_DELAY_ST_FULLSTRIP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_ST_FULLSTRIP = sd->K_LOCK_ST_FULLSTRIP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_ST_FULLSTRIP = gettick() + battle_config.WOE_K_DELAY_ST_FULLSTRIP;
				else
					sd->K_CHK_ST_FULLSTRIP = gettick() + battle_config.K_DELAY_ST_FULLSTRIP;

				sd->K_LOCK_ST_FULLSTRIP = 0;
			}
			break;
		case CR_SLIMPITCHER:
			if(DIFF_TICK(sd->K_CHK_CR_SLIMPITCHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_SLIMPITCHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_SLIMPITCHER >= (battle_config.WOE_K_DELAY_CR_SLIMPITCHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_SLIMPITCHER >= (battle_config.K_DELAY_CR_SLIMPITCHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_SLIMPITCHER = sd->K_LOCK_CR_SLIMPITCHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_SLIMPITCHER = gettick() + battle_config.WOE_K_DELAY_CR_SLIMPITCHER;
				else
					sd->K_CHK_CR_SLIMPITCHER = gettick() + battle_config.K_DELAY_CR_SLIMPITCHER;

				sd->K_LOCK_CR_SLIMPITCHER = 0;
			}
			break;
		case CR_FULLPROTECTION:
			if(DIFF_TICK(sd->K_CHK_CR_FULLPROTECTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_FULLPROTECTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_FULLPROTECTION >= (battle_config.WOE_K_DELAY_CR_FULLPROTECTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_FULLPROTECTION >= (battle_config.K_DELAY_CR_FULLPROTECTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_FULLPROTECTION = sd->K_LOCK_CR_FULLPROTECTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_FULLPROTECTION = gettick() + battle_config.WOE_K_DELAY_CR_FULLPROTECTION;
				else
					sd->K_CHK_CR_FULLPROTECTION = gettick() + battle_config.K_DELAY_CR_FULLPROTECTION;

				sd->K_LOCK_CR_FULLPROTECTION = 0;
			}
			break;
		case PA_SHIELDCHAIN:
			if(DIFF_TICK(sd->K_CHK_PA_SHIELDCHAIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PA_SHIELDCHAIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PA_SHIELDCHAIN >= (battle_config.WOE_K_DELAY_PA_SHIELDCHAIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PA_SHIELDCHAIN >= (battle_config.K_DELAY_PA_SHIELDCHAIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PA_SHIELDCHAIN = sd->K_LOCK_PA_SHIELDCHAIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PA_SHIELDCHAIN = gettick() + battle_config.WOE_K_DELAY_PA_SHIELDCHAIN;
				else
					sd->K_CHK_PA_SHIELDCHAIN = gettick() + battle_config.K_DELAY_PA_SHIELDCHAIN;

				sd->K_LOCK_PA_SHIELDCHAIN = 0;
			}
			break;
		case HP_MANARECHARGE:
			if(DIFF_TICK(sd->K_CHK_HP_MANARECHARGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HP_MANARECHARGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HP_MANARECHARGE >= (battle_config.WOE_K_DELAY_HP_MANARECHARGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HP_MANARECHARGE >= (battle_config.K_DELAY_HP_MANARECHARGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HP_MANARECHARGE = sd->K_LOCK_HP_MANARECHARGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HP_MANARECHARGE = gettick() + battle_config.WOE_K_DELAY_HP_MANARECHARGE;
				else
					sd->K_CHK_HP_MANARECHARGE = gettick() + battle_config.K_DELAY_HP_MANARECHARGE;

				sd->K_LOCK_HP_MANARECHARGE = 0;
			}
			break;
		case PF_DOUBLECASTING:
			if(DIFF_TICK(sd->K_CHK_PF_DOUBLECASTING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PF_DOUBLECASTING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PF_DOUBLECASTING >= (battle_config.WOE_K_DELAY_PF_DOUBLECASTING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PF_DOUBLECASTING >= (battle_config.K_DELAY_PF_DOUBLECASTING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PF_DOUBLECASTING = sd->K_LOCK_PF_DOUBLECASTING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PF_DOUBLECASTING = gettick() + battle_config.WOE_K_DELAY_PF_DOUBLECASTING;
				else
					sd->K_CHK_PF_DOUBLECASTING = gettick() + battle_config.K_DELAY_PF_DOUBLECASTING;

				sd->K_LOCK_PF_DOUBLECASTING = 0;
			}
			break;
		case HW_GANBANTEIN:
			if(DIFF_TICK(sd->K_CHK_HW_GANBANTEIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HW_GANBANTEIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HW_GANBANTEIN >= (battle_config.WOE_K_DELAY_HW_GANBANTEIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HW_GANBANTEIN >= (battle_config.K_DELAY_HW_GANBANTEIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HW_GANBANTEIN = sd->K_LOCK_HW_GANBANTEIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HW_GANBANTEIN = gettick() + battle_config.WOE_K_DELAY_HW_GANBANTEIN;
				else
					sd->K_CHK_HW_GANBANTEIN = gettick() + battle_config.K_DELAY_HW_GANBANTEIN;

				sd->K_LOCK_HW_GANBANTEIN = 0;
			}
			break;
		case HW_GRAVITATION:
			if(DIFF_TICK(sd->K_CHK_HW_GRAVITATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HW_GRAVITATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HW_GRAVITATION >= (battle_config.WOE_K_DELAY_HW_GRAVITATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HW_GRAVITATION >= (battle_config.K_DELAY_HW_GRAVITATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HW_GRAVITATION = sd->K_LOCK_HW_GRAVITATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HW_GRAVITATION = gettick() + battle_config.WOE_K_DELAY_HW_GRAVITATION;
				else
					sd->K_CHK_HW_GRAVITATION = gettick() + battle_config.K_DELAY_HW_GRAVITATION;

				sd->K_LOCK_HW_GRAVITATION = 0;
			}
			break;
		case WS_CARTTERMINATION:
			if(DIFF_TICK(sd->K_CHK_WS_CARTTERMINATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WS_CARTTERMINATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WS_CARTTERMINATION >= (battle_config.WOE_K_DELAY_WS_CARTTERMINATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WS_CARTTERMINATION >= (battle_config.K_DELAY_WS_CARTTERMINATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WS_CARTTERMINATION = sd->K_LOCK_WS_CARTTERMINATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WS_CARTTERMINATION = gettick() + battle_config.WOE_K_DELAY_WS_CARTTERMINATION;
				else
					sd->K_CHK_WS_CARTTERMINATION = gettick() + battle_config.K_DELAY_WS_CARTTERMINATION;

				sd->K_LOCK_WS_CARTTERMINATION = 0;
			}
			break;
		case CG_HERMODE:
			if(DIFF_TICK(sd->K_CHK_CG_HERMODE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CG_HERMODE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CG_HERMODE >= (battle_config.WOE_K_DELAY_CG_HERMODE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CG_HERMODE >= (battle_config.K_DELAY_CG_HERMODE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CG_HERMODE = sd->K_LOCK_CG_HERMODE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CG_HERMODE = gettick() + battle_config.WOE_K_DELAY_CG_HERMODE;
				else
					sd->K_CHK_CG_HERMODE = gettick() + battle_config.K_DELAY_CG_HERMODE;

				sd->K_LOCK_CG_HERMODE = 0;
			}
			break;
		case CG_TAROTCARD:
			if(DIFF_TICK(sd->K_CHK_CG_TAROTCARD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CG_TAROTCARD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CG_TAROTCARD >= (battle_config.WOE_K_DELAY_CG_TAROTCARD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CG_TAROTCARD >= (battle_config.K_DELAY_CG_TAROTCARD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CG_TAROTCARD = sd->K_LOCK_CG_TAROTCARD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CG_TAROTCARD = gettick() + battle_config.WOE_K_DELAY_CG_TAROTCARD;
				else
					sd->K_CHK_CG_TAROTCARD = gettick() + battle_config.K_DELAY_CG_TAROTCARD;

				sd->K_LOCK_CG_TAROTCARD = 0;
			}
			break;
		case CR_ACIDDEMONSTRATION:
			if(DIFF_TICK(sd->K_CHK_CR_ACIDDEMONSTRATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_CR_ACIDDEMONSTRATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_CR_ACIDDEMONSTRATION >= (battle_config.WOE_K_DELAY_CR_ACIDDEMONSTRATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_CR_ACIDDEMONSTRATION >= (battle_config.K_DELAY_CR_ACIDDEMONSTRATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_CR_ACIDDEMONSTRATION = sd->K_LOCK_CR_ACIDDEMONSTRATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_CR_ACIDDEMONSTRATION = gettick() + battle_config.WOE_K_DELAY_CR_ACIDDEMONSTRATION;
				else
					sd->K_CHK_CR_ACIDDEMONSTRATION = gettick() + battle_config.K_DELAY_CR_ACIDDEMONSTRATION;

				sd->K_LOCK_CR_ACIDDEMONSTRATION = 0;
			}
			break;
		case SL_HIGH:
			if(DIFF_TICK(sd->K_CHK_SL_HIGH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SL_HIGH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SL_HIGH >= (battle_config.WOE_K_DELAY_SL_HIGH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SL_HIGH >= (battle_config.K_DELAY_SL_HIGH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SL_HIGH = sd->K_LOCK_SL_HIGH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SL_HIGH = gettick() + battle_config.WOE_K_DELAY_SL_HIGH;
				else
					sd->K_CHK_SL_HIGH = gettick() + battle_config.K_DELAY_SL_HIGH;

				sd->K_LOCK_SL_HIGH = 0;
			}
			break;
		case HT_POWER:
			if(DIFF_TICK(sd->K_CHK_HT_POWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HT_POWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HT_POWER >= (battle_config.WOE_K_DELAY_HT_POWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HT_POWER >= (battle_config.K_DELAY_HT_POWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HT_POWER = sd->K_LOCK_HT_POWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HT_POWER = gettick() + battle_config.WOE_K_DELAY_HT_POWER;
				else
					sd->K_CHK_HT_POWER = gettick() + battle_config.K_DELAY_HT_POWER;

				sd->K_LOCK_HT_POWER = 0;
			}
			break;
		case GS_TRIPLEACTION:
			if(DIFF_TICK(sd->K_CHK_GS_TRIPLEACTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_TRIPLEACTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_TRIPLEACTION >= (battle_config.WOE_K_DELAY_GS_TRIPLEACTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_TRIPLEACTION >= (battle_config.K_DELAY_GS_TRIPLEACTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_TRIPLEACTION = sd->K_LOCK_GS_TRIPLEACTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_TRIPLEACTION = gettick() + battle_config.WOE_K_DELAY_GS_TRIPLEACTION;
				else
					sd->K_CHK_GS_TRIPLEACTION = gettick() + battle_config.K_DELAY_GS_TRIPLEACTION;

				sd->K_LOCK_GS_TRIPLEACTION = 0;
			}
			break;
		case GS_BULLSEYE:
			if(DIFF_TICK(sd->K_CHK_GS_BULLSEYE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_BULLSEYE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_BULLSEYE >= (battle_config.WOE_K_DELAY_GS_BULLSEYE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_BULLSEYE >= (battle_config.K_DELAY_GS_BULLSEYE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_BULLSEYE = sd->K_LOCK_GS_BULLSEYE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_BULLSEYE = gettick() + battle_config.WOE_K_DELAY_GS_BULLSEYE;
				else
					sd->K_CHK_GS_BULLSEYE = gettick() + battle_config.K_DELAY_GS_BULLSEYE;

				sd->K_LOCK_GS_BULLSEYE = 0;
			}
			break;
		case GS_MADNESSCANCEL:
			if(DIFF_TICK(sd->K_CHK_GS_MADNESSCANCEL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_MADNESSCANCEL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_MADNESSCANCEL >= (battle_config.WOE_K_DELAY_GS_MADNESSCANCEL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_MADNESSCANCEL >= (battle_config.K_DELAY_GS_MADNESSCANCEL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_MADNESSCANCEL = sd->K_LOCK_GS_MADNESSCANCEL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_MADNESSCANCEL = gettick() + battle_config.WOE_K_DELAY_GS_MADNESSCANCEL;
				else
					sd->K_CHK_GS_MADNESSCANCEL = gettick() + battle_config.K_DELAY_GS_MADNESSCANCEL;

				sd->K_LOCK_GS_MADNESSCANCEL = 0;
			}
			break;
		case GS_INCREASING:
			if(DIFF_TICK(sd->K_CHK_GS_INCREASING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_INCREASING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_INCREASING >= (battle_config.WOE_K_DELAY_GS_INCREASING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_INCREASING >= (battle_config.K_DELAY_GS_INCREASING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_INCREASING = sd->K_LOCK_GS_INCREASING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_INCREASING = gettick() + battle_config.WOE_K_DELAY_GS_INCREASING;
				else
					sd->K_CHK_GS_INCREASING = gettick() + battle_config.K_DELAY_GS_INCREASING;

				sd->K_LOCK_GS_INCREASING = 0;
			}
			break;
		case GS_MAGICALBULLET:
			if(DIFF_TICK(sd->K_CHK_GS_MAGICALBULLET,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_MAGICALBULLET - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_MAGICALBULLET >= (battle_config.WOE_K_DELAY_GS_MAGICALBULLET/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_MAGICALBULLET >= (battle_config.K_DELAY_GS_MAGICALBULLET/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_MAGICALBULLET = sd->K_LOCK_GS_MAGICALBULLET +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_MAGICALBULLET = gettick() + battle_config.WOE_K_DELAY_GS_MAGICALBULLET;
				else
					sd->K_CHK_GS_MAGICALBULLET = gettick() + battle_config.K_DELAY_GS_MAGICALBULLET;

				sd->K_LOCK_GS_MAGICALBULLET = 0;
			}
			break;
		case GS_CRACKER:
			if(DIFF_TICK(sd->K_CHK_GS_CRACKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_CRACKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_CRACKER >= (battle_config.WOE_K_DELAY_GS_CRACKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_CRACKER >= (battle_config.K_DELAY_GS_CRACKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_CRACKER = sd->K_LOCK_GS_CRACKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_CRACKER = gettick() + battle_config.WOE_K_DELAY_GS_CRACKER;
				else
					sd->K_CHK_GS_CRACKER = gettick() + battle_config.K_DELAY_GS_CRACKER;

				sd->K_LOCK_GS_CRACKER = 0;
			}
			break;
		case GS_SINGLEACTION:
			if(DIFF_TICK(sd->K_CHK_GS_SINGLEACTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_SINGLEACTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_SINGLEACTION >= (battle_config.WOE_K_DELAY_GS_SINGLEACTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_SINGLEACTION >= (battle_config.K_DELAY_GS_SINGLEACTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_SINGLEACTION = sd->K_LOCK_GS_SINGLEACTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_SINGLEACTION = gettick() + battle_config.WOE_K_DELAY_GS_SINGLEACTION;
				else
					sd->K_CHK_GS_SINGLEACTION = gettick() + battle_config.K_DELAY_GS_SINGLEACTION;

				sd->K_LOCK_GS_SINGLEACTION = 0;
			}
			break;
		case GS_CHAINACTION:
			if(DIFF_TICK(sd->K_CHK_GS_CHAINACTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_CHAINACTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_CHAINACTION >= (battle_config.WOE_K_DELAY_GS_CHAINACTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_CHAINACTION >= (battle_config.K_DELAY_GS_CHAINACTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_CHAINACTION = sd->K_LOCK_GS_CHAINACTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_CHAINACTION = gettick() + battle_config.WOE_K_DELAY_GS_CHAINACTION;
				else
					sd->K_CHK_GS_CHAINACTION = gettick() + battle_config.K_DELAY_GS_CHAINACTION;

				sd->K_LOCK_GS_CHAINACTION = 0;
			}
			break;
		case GS_TRACKING:
			if(DIFF_TICK(sd->K_CHK_GS_TRACKING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_TRACKING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_TRACKING >= (battle_config.WOE_K_DELAY_GS_TRACKING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_TRACKING >= (battle_config.K_DELAY_GS_TRACKING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_TRACKING = sd->K_LOCK_GS_TRACKING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_TRACKING = gettick() + battle_config.WOE_K_DELAY_GS_TRACKING;
				else
					sd->K_CHK_GS_TRACKING = gettick() + battle_config.K_DELAY_GS_TRACKING;

				sd->K_LOCK_GS_TRACKING = 0;
			}
			break;
		case GS_DISARM:
			if(DIFF_TICK(sd->K_CHK_GS_DISARM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_DISARM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_DISARM >= (battle_config.WOE_K_DELAY_GS_DISARM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_DISARM >= (battle_config.K_DELAY_GS_DISARM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_DISARM = sd->K_LOCK_GS_DISARM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_DISARM = gettick() + battle_config.WOE_K_DELAY_GS_DISARM;
				else
					sd->K_CHK_GS_DISARM = gettick() + battle_config.K_DELAY_GS_DISARM;

				sd->K_LOCK_GS_DISARM = 0;
			}
			break;
		case GS_PIERCINGSHOT:
			if(DIFF_TICK(sd->K_CHK_GS_PIERCINGSHOT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_PIERCINGSHOT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_PIERCINGSHOT >= (battle_config.WOE_K_DELAY_GS_PIERCINGSHOT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_PIERCINGSHOT >= (battle_config.K_DELAY_GS_PIERCINGSHOT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_PIERCINGSHOT = sd->K_LOCK_GS_PIERCINGSHOT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_PIERCINGSHOT = gettick() + battle_config.WOE_K_DELAY_GS_PIERCINGSHOT;
				else
					sd->K_CHK_GS_PIERCINGSHOT = gettick() + battle_config.K_DELAY_GS_PIERCINGSHOT;

				sd->K_LOCK_GS_PIERCINGSHOT = 0;
			}
			break;
		case GS_RAPIDSHOWER:
			if(DIFF_TICK(sd->K_CHK_GS_RAPIDSHOWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_RAPIDSHOWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_RAPIDSHOWER >= (battle_config.WOE_K_DELAY_GS_RAPIDSHOWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_RAPIDSHOWER >= (battle_config.K_DELAY_GS_RAPIDSHOWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_RAPIDSHOWER = sd->K_LOCK_GS_RAPIDSHOWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_RAPIDSHOWER = gettick() + battle_config.WOE_K_DELAY_GS_RAPIDSHOWER;
				else
					sd->K_CHK_GS_RAPIDSHOWER = gettick() + battle_config.K_DELAY_GS_RAPIDSHOWER;

				sd->K_LOCK_GS_RAPIDSHOWER = 0;
			}
			break;
		case GS_DESPERADO:
			if(DIFF_TICK(sd->K_CHK_GS_DESPERADO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_DESPERADO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_DESPERADO >= (battle_config.WOE_K_DELAY_GS_DESPERADO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_DESPERADO >= (battle_config.K_DELAY_GS_DESPERADO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_DESPERADO = sd->K_LOCK_GS_DESPERADO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_DESPERADO = gettick() + battle_config.WOE_K_DELAY_GS_DESPERADO;
				else
					sd->K_CHK_GS_DESPERADO = gettick() + battle_config.K_DELAY_GS_DESPERADO;

				sd->K_LOCK_GS_DESPERADO = 0;
			}
			break;
		case GS_GATLINGFEVER:
			if(DIFF_TICK(sd->K_CHK_GS_GATLINGFEVER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_GATLINGFEVER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_GATLINGFEVER >= (battle_config.WOE_K_DELAY_GS_GATLINGFEVER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_GATLINGFEVER >= (battle_config.K_DELAY_GS_GATLINGFEVER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_GATLINGFEVER = sd->K_LOCK_GS_GATLINGFEVER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_GATLINGFEVER = gettick() + battle_config.WOE_K_DELAY_GS_GATLINGFEVER;
				else
					sd->K_CHK_GS_GATLINGFEVER = gettick() + battle_config.K_DELAY_GS_GATLINGFEVER;

				sd->K_LOCK_GS_GATLINGFEVER = 0;
			}
			break;
		case GS_DUST:
			if(DIFF_TICK(sd->K_CHK_GS_DUST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_DUST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_DUST >= (battle_config.WOE_K_DELAY_GS_DUST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_DUST >= (battle_config.K_DELAY_GS_DUST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_DUST = sd->K_LOCK_GS_DUST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_DUST = gettick() + battle_config.WOE_K_DELAY_GS_DUST;
				else
					sd->K_CHK_GS_DUST = gettick() + battle_config.K_DELAY_GS_DUST;

				sd->K_LOCK_GS_DUST = 0;
			}
			break;
		case GS_FULLBUSTER:
			if(DIFF_TICK(sd->K_CHK_GS_FULLBUSTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_FULLBUSTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_FULLBUSTER >= (battle_config.WOE_K_DELAY_GS_FULLBUSTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_FULLBUSTER >= (battle_config.K_DELAY_GS_FULLBUSTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_FULLBUSTER = sd->K_LOCK_GS_FULLBUSTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_FULLBUSTER = gettick() + battle_config.WOE_K_DELAY_GS_FULLBUSTER;
				else
					sd->K_CHK_GS_FULLBUSTER = gettick() + battle_config.K_DELAY_GS_FULLBUSTER;

				sd->K_LOCK_GS_FULLBUSTER = 0;
			}
			break;
		case GS_SPREADATTACK:
			if(DIFF_TICK(sd->K_CHK_GS_SPREADATTACK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_SPREADATTACK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_SPREADATTACK >= (battle_config.WOE_K_DELAY_GS_SPREADATTACK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_SPREADATTACK >= (battle_config.K_DELAY_GS_SPREADATTACK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_SPREADATTACK = sd->K_LOCK_GS_SPREADATTACK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_SPREADATTACK = gettick() + battle_config.WOE_K_DELAY_GS_SPREADATTACK;
				else
					sd->K_CHK_GS_SPREADATTACK = gettick() + battle_config.K_DELAY_GS_SPREADATTACK;

				sd->K_LOCK_GS_SPREADATTACK = 0;
			}
			break;
		case GS_GROUNDDRIFT:
			if(DIFF_TICK(sd->K_CHK_GS_GROUNDDRIFT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GS_GROUNDDRIFT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GS_GROUNDDRIFT >= (battle_config.WOE_K_DELAY_GS_GROUNDDRIFT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GS_GROUNDDRIFT >= (battle_config.K_DELAY_GS_GROUNDDRIFT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GS_GROUNDDRIFT = sd->K_LOCK_GS_GROUNDDRIFT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GS_GROUNDDRIFT = gettick() + battle_config.WOE_K_DELAY_GS_GROUNDDRIFT;
				else
					sd->K_CHK_GS_GROUNDDRIFT = gettick() + battle_config.K_DELAY_GS_GROUNDDRIFT;

				sd->K_LOCK_GS_GROUNDDRIFT = 0;
			}
			break;
		case NJ_TOBIDOUGU:
			if(DIFF_TICK(sd->K_CHK_NJ_TOBIDOUGU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_TOBIDOUGU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_TOBIDOUGU >= (battle_config.WOE_K_DELAY_NJ_TOBIDOUGU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_TOBIDOUGU >= (battle_config.K_DELAY_NJ_TOBIDOUGU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_TOBIDOUGU = sd->K_LOCK_NJ_TOBIDOUGU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_TOBIDOUGU = gettick() + battle_config.WOE_K_DELAY_NJ_TOBIDOUGU;
				else
					sd->K_CHK_NJ_TOBIDOUGU = gettick() + battle_config.K_DELAY_NJ_TOBIDOUGU;

				sd->K_LOCK_NJ_TOBIDOUGU = 0;
			}
			break;
		case NJ_SYURIKEN:
			if(DIFF_TICK(sd->K_CHK_NJ_SYURIKEN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_SYURIKEN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_SYURIKEN >= (battle_config.WOE_K_DELAY_NJ_SYURIKEN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_SYURIKEN >= (battle_config.K_DELAY_NJ_SYURIKEN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_SYURIKEN = sd->K_LOCK_NJ_SYURIKEN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_SYURIKEN = gettick() + battle_config.WOE_K_DELAY_NJ_SYURIKEN;
				else
					sd->K_CHK_NJ_SYURIKEN = gettick() + battle_config.K_DELAY_NJ_SYURIKEN;

				sd->K_LOCK_NJ_SYURIKEN = 0;
			}
			break;
		case NJ_KUNAI:
			if(DIFF_TICK(sd->K_CHK_NJ_KUNAI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KUNAI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KUNAI >= (battle_config.WOE_K_DELAY_NJ_KUNAI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KUNAI >= (battle_config.K_DELAY_NJ_KUNAI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KUNAI = sd->K_LOCK_NJ_KUNAI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KUNAI = gettick() + battle_config.WOE_K_DELAY_NJ_KUNAI;
				else
					sd->K_CHK_NJ_KUNAI = gettick() + battle_config.K_DELAY_NJ_KUNAI;

				sd->K_LOCK_NJ_KUNAI = 0;
			}
			break;
		case NJ_HUUMA:
			if(DIFF_TICK(sd->K_CHK_NJ_HUUMA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_HUUMA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_HUUMA >= (battle_config.WOE_K_DELAY_NJ_HUUMA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_HUUMA >= (battle_config.K_DELAY_NJ_HUUMA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_HUUMA = sd->K_LOCK_NJ_HUUMA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_HUUMA = gettick() + battle_config.WOE_K_DELAY_NJ_HUUMA;
				else
					sd->K_CHK_NJ_HUUMA = gettick() + battle_config.K_DELAY_NJ_HUUMA;

				sd->K_LOCK_NJ_HUUMA = 0;
			}
			break;
		case NJ_ZENYNAGE:
			if(DIFF_TICK(sd->K_CHK_NJ_ZENYNAGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_ZENYNAGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_ZENYNAGE >= (battle_config.WOE_K_DELAY_NJ_ZENYNAGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_ZENYNAGE >= (battle_config.K_DELAY_NJ_ZENYNAGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_ZENYNAGE = sd->K_LOCK_NJ_ZENYNAGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_ZENYNAGE = gettick() + battle_config.WOE_K_DELAY_NJ_ZENYNAGE;
				else
					sd->K_CHK_NJ_ZENYNAGE = gettick() + battle_config.K_DELAY_NJ_ZENYNAGE;

				sd->K_LOCK_NJ_ZENYNAGE = 0;
			}
			break;
		case NJ_TATAMIGAESHI:
			if(DIFF_TICK(sd->K_CHK_NJ_TATAMIGAESHI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_TATAMIGAESHI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_TATAMIGAESHI >= (battle_config.WOE_K_DELAY_NJ_TATAMIGAESHI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_TATAMIGAESHI >= (battle_config.K_DELAY_NJ_TATAMIGAESHI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_TATAMIGAESHI = sd->K_LOCK_NJ_TATAMIGAESHI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_TATAMIGAESHI = gettick() + battle_config.WOE_K_DELAY_NJ_TATAMIGAESHI;
				else
					sd->K_CHK_NJ_TATAMIGAESHI = gettick() + battle_config.K_DELAY_NJ_TATAMIGAESHI;

				sd->K_LOCK_NJ_TATAMIGAESHI = 0;
			}
			break;
		case NJ_KASUMIKIRI:
			if(DIFF_TICK(sd->K_CHK_NJ_KASUMIKIRI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KASUMIKIRI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KASUMIKIRI >= (battle_config.WOE_K_DELAY_NJ_KASUMIKIRI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KASUMIKIRI >= (battle_config.K_DELAY_NJ_KASUMIKIRI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KASUMIKIRI = sd->K_LOCK_NJ_KASUMIKIRI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KASUMIKIRI = gettick() + battle_config.WOE_K_DELAY_NJ_KASUMIKIRI;
				else
					sd->K_CHK_NJ_KASUMIKIRI = gettick() + battle_config.K_DELAY_NJ_KASUMIKIRI;

				sd->K_LOCK_NJ_KASUMIKIRI = 0;
			}
			break;
		case NJ_SHADOWJUMP:
			if(DIFF_TICK(sd->K_CHK_NJ_SHADOWJUMP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_SHADOWJUMP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_SHADOWJUMP >= (battle_config.WOE_K_DELAY_NJ_SHADOWJUMP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_SHADOWJUMP >= (battle_config.K_DELAY_NJ_SHADOWJUMP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_SHADOWJUMP = sd->K_LOCK_NJ_SHADOWJUMP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_SHADOWJUMP = gettick() + battle_config.WOE_K_DELAY_NJ_SHADOWJUMP;
				else
					sd->K_CHK_NJ_SHADOWJUMP = gettick() + battle_config.K_DELAY_NJ_SHADOWJUMP;

				sd->K_LOCK_NJ_SHADOWJUMP = 0;
			}
			break;
		case NJ_KIRIKAGE:
			if(DIFF_TICK(sd->K_CHK_NJ_KIRIKAGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KIRIKAGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KIRIKAGE >= (battle_config.WOE_K_DELAY_NJ_KIRIKAGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KIRIKAGE >= (battle_config.K_DELAY_NJ_KIRIKAGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KIRIKAGE = sd->K_LOCK_NJ_KIRIKAGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KIRIKAGE = gettick() + battle_config.WOE_K_DELAY_NJ_KIRIKAGE;
				else
					sd->K_CHK_NJ_KIRIKAGE = gettick() + battle_config.K_DELAY_NJ_KIRIKAGE;

				sd->K_LOCK_NJ_KIRIKAGE = 0;
			}
			break;
		case NJ_UTSUSEMI:
			if(DIFF_TICK(sd->K_CHK_NJ_UTSUSEMI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_UTSUSEMI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_UTSUSEMI >= (battle_config.WOE_K_DELAY_NJ_UTSUSEMI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_UTSUSEMI >= (battle_config.K_DELAY_NJ_UTSUSEMI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_UTSUSEMI = sd->K_LOCK_NJ_UTSUSEMI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_UTSUSEMI = gettick() + battle_config.WOE_K_DELAY_NJ_UTSUSEMI;
				else
					sd->K_CHK_NJ_UTSUSEMI = gettick() + battle_config.K_DELAY_NJ_UTSUSEMI;

				sd->K_LOCK_NJ_UTSUSEMI = 0;
			}
			break;
		case NJ_BUNSINJYUTSU:
			if(DIFF_TICK(sd->K_CHK_NJ_BUNSINJYUTSU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_BUNSINJYUTSU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_BUNSINJYUTSU >= (battle_config.WOE_K_DELAY_NJ_BUNSINJYUTSU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_BUNSINJYUTSU >= (battle_config.K_DELAY_NJ_BUNSINJYUTSU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_BUNSINJYUTSU = sd->K_LOCK_NJ_BUNSINJYUTSU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_BUNSINJYUTSU = gettick() + battle_config.WOE_K_DELAY_NJ_BUNSINJYUTSU;
				else
					sd->K_CHK_NJ_BUNSINJYUTSU = gettick() + battle_config.K_DELAY_NJ_BUNSINJYUTSU;

				sd->K_LOCK_NJ_BUNSINJYUTSU = 0;
			}
			break;
		case NJ_NINPOU:
			if(DIFF_TICK(sd->K_CHK_NJ_NINPOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_NINPOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_NINPOU >= (battle_config.WOE_K_DELAY_NJ_NINPOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_NINPOU >= (battle_config.K_DELAY_NJ_NINPOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_NINPOU = sd->K_LOCK_NJ_NINPOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_NINPOU = gettick() + battle_config.WOE_K_DELAY_NJ_NINPOU;
				else
					sd->K_CHK_NJ_NINPOU = gettick() + battle_config.K_DELAY_NJ_NINPOU;

				sd->K_LOCK_NJ_NINPOU = 0;
			}
			break;
		case NJ_KOUENKA:
			if(DIFF_TICK(sd->K_CHK_NJ_KOUENKA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KOUENKA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KOUENKA >= (battle_config.WOE_K_DELAY_NJ_KOUENKA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KOUENKA >= (battle_config.K_DELAY_NJ_KOUENKA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KOUENKA = sd->K_LOCK_NJ_KOUENKA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KOUENKA = gettick() + battle_config.WOE_K_DELAY_NJ_KOUENKA;
				else
					sd->K_CHK_NJ_KOUENKA = gettick() + battle_config.K_DELAY_NJ_KOUENKA;

				sd->K_LOCK_NJ_KOUENKA = 0;
			}
			break;
		case NJ_KAENSIN:
			if(DIFF_TICK(sd->K_CHK_NJ_KAENSIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KAENSIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KAENSIN >= (battle_config.WOE_K_DELAY_NJ_KAENSIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KAENSIN >= (battle_config.K_DELAY_NJ_KAENSIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KAENSIN = sd->K_LOCK_NJ_KAENSIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KAENSIN = gettick() + battle_config.WOE_K_DELAY_NJ_KAENSIN;
				else
					sd->K_CHK_NJ_KAENSIN = gettick() + battle_config.K_DELAY_NJ_KAENSIN;

				sd->K_LOCK_NJ_KAENSIN = 0;
			}
			break;
		case NJ_BAKUENRYU:
			if(DIFF_TICK(sd->K_CHK_NJ_BAKUENRYU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_BAKUENRYU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_BAKUENRYU >= (battle_config.WOE_K_DELAY_NJ_BAKUENRYU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_BAKUENRYU >= (battle_config.K_DELAY_NJ_BAKUENRYU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_BAKUENRYU = sd->K_LOCK_NJ_BAKUENRYU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_BAKUENRYU = gettick() + battle_config.WOE_K_DELAY_NJ_BAKUENRYU;
				else
					sd->K_CHK_NJ_BAKUENRYU = gettick() + battle_config.K_DELAY_NJ_BAKUENRYU;

				sd->K_LOCK_NJ_BAKUENRYU = 0;
			}
			break;
		case NJ_HYOUSENSOU:
			if(DIFF_TICK(sd->K_CHK_NJ_HYOUSENSOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_HYOUSENSOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_HYOUSENSOU >= (battle_config.WOE_K_DELAY_NJ_HYOUSENSOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_HYOUSENSOU >= (battle_config.K_DELAY_NJ_HYOUSENSOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_HYOUSENSOU = sd->K_LOCK_NJ_HYOUSENSOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_HYOUSENSOU = gettick() + battle_config.WOE_K_DELAY_NJ_HYOUSENSOU;
				else
					sd->K_CHK_NJ_HYOUSENSOU = gettick() + battle_config.K_DELAY_NJ_HYOUSENSOU;

				sd->K_LOCK_NJ_HYOUSENSOU = 0;
			}
			break;
		case NJ_SUITON:
			if(DIFF_TICK(sd->K_CHK_NJ_SUITON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_SUITON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_SUITON >= (battle_config.WOE_K_DELAY_NJ_SUITON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_SUITON >= (battle_config.K_DELAY_NJ_SUITON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_SUITON = sd->K_LOCK_NJ_SUITON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_SUITON = gettick() + battle_config.WOE_K_DELAY_NJ_SUITON;
				else
					sd->K_CHK_NJ_SUITON = gettick() + battle_config.K_DELAY_NJ_SUITON;

				sd->K_LOCK_NJ_SUITON = 0;
			}
			break;
		case NJ_HYOUSYOURAKU:
			if(DIFF_TICK(sd->K_CHK_NJ_HYOUSYOURAKU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_HYOUSYOURAKU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_HYOUSYOURAKU >= (battle_config.WOE_K_DELAY_NJ_HYOUSYOURAKU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_HYOUSYOURAKU >= (battle_config.K_DELAY_NJ_HYOUSYOURAKU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_HYOUSYOURAKU = sd->K_LOCK_NJ_HYOUSYOURAKU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_HYOUSYOURAKU = gettick() + battle_config.WOE_K_DELAY_NJ_HYOUSYOURAKU;
				else
					sd->K_CHK_NJ_HYOUSYOURAKU = gettick() + battle_config.K_DELAY_NJ_HYOUSYOURAKU;

				sd->K_LOCK_NJ_HYOUSYOURAKU = 0;
			}
			break;
		case NJ_HUUJIN:
			if(DIFF_TICK(sd->K_CHK_NJ_HUUJIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_HUUJIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_HUUJIN >= (battle_config.WOE_K_DELAY_NJ_HUUJIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_HUUJIN >= (battle_config.K_DELAY_NJ_HUUJIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_HUUJIN = sd->K_LOCK_NJ_HUUJIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_HUUJIN = gettick() + battle_config.WOE_K_DELAY_NJ_HUUJIN;
				else
					sd->K_CHK_NJ_HUUJIN = gettick() + battle_config.K_DELAY_NJ_HUUJIN;

				sd->K_LOCK_NJ_HUUJIN = 0;
			}
			break;
		case NJ_RAIGEKISAI:
			if(DIFF_TICK(sd->K_CHK_NJ_RAIGEKISAI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_RAIGEKISAI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_RAIGEKISAI >= (battle_config.WOE_K_DELAY_NJ_RAIGEKISAI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_RAIGEKISAI >= (battle_config.K_DELAY_NJ_RAIGEKISAI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_RAIGEKISAI = sd->K_LOCK_NJ_RAIGEKISAI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_RAIGEKISAI = gettick() + battle_config.WOE_K_DELAY_NJ_RAIGEKISAI;
				else
					sd->K_CHK_NJ_RAIGEKISAI = gettick() + battle_config.K_DELAY_NJ_RAIGEKISAI;

				sd->K_LOCK_NJ_RAIGEKISAI = 0;
			}
			break;
		case NJ_KAMAITACHI:
			if(DIFF_TICK(sd->K_CHK_NJ_KAMAITACHI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_KAMAITACHI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_KAMAITACHI >= (battle_config.WOE_K_DELAY_NJ_KAMAITACHI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_KAMAITACHI >= (battle_config.K_DELAY_NJ_KAMAITACHI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_KAMAITACHI = sd->K_LOCK_NJ_KAMAITACHI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_KAMAITACHI = gettick() + battle_config.WOE_K_DELAY_NJ_KAMAITACHI;
				else
					sd->K_CHK_NJ_KAMAITACHI = gettick() + battle_config.K_DELAY_NJ_KAMAITACHI;

				sd->K_LOCK_NJ_KAMAITACHI = 0;
			}
			break;
		case NJ_NEN:
			if(DIFF_TICK(sd->K_CHK_NJ_NEN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_NEN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_NEN >= (battle_config.WOE_K_DELAY_NJ_NEN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_NEN >= (battle_config.K_DELAY_NJ_NEN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_NEN = sd->K_LOCK_NJ_NEN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_NEN = gettick() + battle_config.WOE_K_DELAY_NJ_NEN;
				else
					sd->K_CHK_NJ_NEN = gettick() + battle_config.K_DELAY_NJ_NEN;

				sd->K_LOCK_NJ_NEN = 0;
			}
			break;
		case NJ_ISSEN:
			if(DIFF_TICK(sd->K_CHK_NJ_ISSEN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NJ_ISSEN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NJ_ISSEN >= (battle_config.WOE_K_DELAY_NJ_ISSEN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NJ_ISSEN >= (battle_config.K_DELAY_NJ_ISSEN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NJ_ISSEN = sd->K_LOCK_NJ_ISSEN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NJ_ISSEN = gettick() + battle_config.WOE_K_DELAY_NJ_ISSEN;
				else
					sd->K_CHK_NJ_ISSEN = gettick() + battle_config.K_DELAY_NJ_ISSEN;

				sd->K_LOCK_NJ_ISSEN = 0;
			}
			break;
		case KN_CHARGEATK:
			if(DIFF_TICK(sd->K_CHK_KN_CHARGEATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KN_CHARGEATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KN_CHARGEATK >= (battle_config.WOE_K_DELAY_KN_CHARGEATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KN_CHARGEATK >= (battle_config.K_DELAY_KN_CHARGEATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KN_CHARGEATK = sd->K_LOCK_KN_CHARGEATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KN_CHARGEATK = gettick() + battle_config.WOE_K_DELAY_KN_CHARGEATK;
				else
					sd->K_CHK_KN_CHARGEATK = gettick() + battle_config.K_DELAY_KN_CHARGEATK;

				sd->K_LOCK_KN_CHARGEATK = 0;
			}
			break;
		case AS_VENOMKNIFE:
			if(DIFF_TICK(sd->K_CHK_AS_VENOMKNIFE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AS_VENOMKNIFE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AS_VENOMKNIFE >= (battle_config.WOE_K_DELAY_AS_VENOMKNIFE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AS_VENOMKNIFE >= (battle_config.K_DELAY_AS_VENOMKNIFE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AS_VENOMKNIFE = sd->K_LOCK_AS_VENOMKNIFE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AS_VENOMKNIFE = gettick() + battle_config.WOE_K_DELAY_AS_VENOMKNIFE;
				else
					sd->K_CHK_AS_VENOMKNIFE = gettick() + battle_config.K_DELAY_AS_VENOMKNIFE;

				sd->K_LOCK_AS_VENOMKNIFE = 0;
			}
			break;
		case RG_CLOSECONFINE:
			if(DIFF_TICK(sd->K_CHK_RG_CLOSECONFINE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RG_CLOSECONFINE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RG_CLOSECONFINE >= (battle_config.WOE_K_DELAY_RG_CLOSECONFINE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RG_CLOSECONFINE >= (battle_config.K_DELAY_RG_CLOSECONFINE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RG_CLOSECONFINE = sd->K_LOCK_RG_CLOSECONFINE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RG_CLOSECONFINE = gettick() + battle_config.WOE_K_DELAY_RG_CLOSECONFINE;
				else
					sd->K_CHK_RG_CLOSECONFINE = gettick() + battle_config.K_DELAY_RG_CLOSECONFINE;

				sd->K_LOCK_RG_CLOSECONFINE = 0;
			}
			break;
		case WZ_SIGHTBLASTER:
			if(DIFF_TICK(sd->K_CHK_WZ_SIGHTBLASTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WZ_SIGHTBLASTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WZ_SIGHTBLASTER >= (battle_config.WOE_K_DELAY_WZ_SIGHTBLASTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WZ_SIGHTBLASTER >= (battle_config.K_DELAY_WZ_SIGHTBLASTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WZ_SIGHTBLASTER = sd->K_LOCK_WZ_SIGHTBLASTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WZ_SIGHTBLASTER = gettick() + battle_config.WOE_K_DELAY_WZ_SIGHTBLASTER;
				else
					sd->K_CHK_WZ_SIGHTBLASTER = gettick() + battle_config.K_DELAY_WZ_SIGHTBLASTER;

				sd->K_LOCK_WZ_SIGHTBLASTER = 0;
			}
			break;
		case HT_PHANTASMIC:
			if(DIFF_TICK(sd->K_CHK_HT_PHANTASMIC,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_HT_PHANTASMIC - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_HT_PHANTASMIC >= (battle_config.WOE_K_DELAY_HT_PHANTASMIC/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_HT_PHANTASMIC >= (battle_config.K_DELAY_HT_PHANTASMIC/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_HT_PHANTASMIC = sd->K_LOCK_HT_PHANTASMIC +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_HT_PHANTASMIC = gettick() + battle_config.WOE_K_DELAY_HT_PHANTASMIC;
				else
					sd->K_CHK_HT_PHANTASMIC = gettick() + battle_config.K_DELAY_HT_PHANTASMIC;

				sd->K_LOCK_HT_PHANTASMIC = 0;
			}
			break;
		case BA_PANGVOICE:
			if(DIFF_TICK(sd->K_CHK_BA_PANGVOICE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_BA_PANGVOICE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_BA_PANGVOICE >= (battle_config.WOE_K_DELAY_BA_PANGVOICE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_BA_PANGVOICE >= (battle_config.K_DELAY_BA_PANGVOICE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_BA_PANGVOICE = sd->K_LOCK_BA_PANGVOICE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_BA_PANGVOICE = gettick() + battle_config.WOE_K_DELAY_BA_PANGVOICE;
				else
					sd->K_CHK_BA_PANGVOICE = gettick() + battle_config.K_DELAY_BA_PANGVOICE;

				sd->K_LOCK_BA_PANGVOICE = 0;
			}
			break;
		case DC_WINKCHARM:
			if(DIFF_TICK(sd->K_CHK_DC_WINKCHARM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DC_WINKCHARM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DC_WINKCHARM >= (battle_config.WOE_K_DELAY_DC_WINKCHARM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DC_WINKCHARM >= (battle_config.K_DELAY_DC_WINKCHARM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DC_WINKCHARM = sd->K_LOCK_DC_WINKCHARM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DC_WINKCHARM = gettick() + battle_config.WOE_K_DELAY_DC_WINKCHARM;
				else
					sd->K_CHK_DC_WINKCHARM = gettick() + battle_config.K_DELAY_DC_WINKCHARM;

				sd->K_LOCK_DC_WINKCHARM = 0;
			}
			break;
		case PR_REDEMPTIO:
			if(DIFF_TICK(sd->K_CHK_PR_REDEMPTIO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_PR_REDEMPTIO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_PR_REDEMPTIO >= (battle_config.WOE_K_DELAY_PR_REDEMPTIO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_PR_REDEMPTIO >= (battle_config.K_DELAY_PR_REDEMPTIO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_PR_REDEMPTIO = sd->K_LOCK_PR_REDEMPTIO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_PR_REDEMPTIO = gettick() + battle_config.WOE_K_DELAY_PR_REDEMPTIO;
				else
					sd->K_CHK_PR_REDEMPTIO = gettick() + battle_config.K_DELAY_PR_REDEMPTIO;

				sd->K_LOCK_PR_REDEMPTIO = 0;
			}
			break;
		case MO_KITRANSLATION:
			if(DIFF_TICK(sd->K_CHK_MO_KITRANSLATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_KITRANSLATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_KITRANSLATION >= (battle_config.WOE_K_DELAY_MO_KITRANSLATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_KITRANSLATION >= (battle_config.K_DELAY_MO_KITRANSLATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_KITRANSLATION = sd->K_LOCK_MO_KITRANSLATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_KITRANSLATION = gettick() + battle_config.WOE_K_DELAY_MO_KITRANSLATION;
				else
					sd->K_CHK_MO_KITRANSLATION = gettick() + battle_config.K_DELAY_MO_KITRANSLATION;

				sd->K_LOCK_MO_KITRANSLATION = 0;
			}
			break;
		case MO_BALKYOUNG:
			if(DIFF_TICK(sd->K_CHK_MO_BALKYOUNG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MO_BALKYOUNG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MO_BALKYOUNG >= (battle_config.WOE_K_DELAY_MO_BALKYOUNG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MO_BALKYOUNG >= (battle_config.K_DELAY_MO_BALKYOUNG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MO_BALKYOUNG = sd->K_LOCK_MO_BALKYOUNG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MO_BALKYOUNG = gettick() + battle_config.WOE_K_DELAY_MO_BALKYOUNG;
				else
					sd->K_CHK_MO_BALKYOUNG = gettick() + battle_config.K_DELAY_MO_BALKYOUNG;

				sd->K_LOCK_MO_BALKYOUNG = 0;
			}
			break;
		case RK_SONICWAVE:
			if(DIFF_TICK(sd->K_CHK_RK_SONICWAVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_SONICWAVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_SONICWAVE >= (battle_config.WOE_K_DELAY_RK_SONICWAVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_SONICWAVE >= (battle_config.K_DELAY_RK_SONICWAVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_SONICWAVE = sd->K_LOCK_RK_SONICWAVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_SONICWAVE = gettick() + battle_config.WOE_K_DELAY_RK_SONICWAVE;
				else
					sd->K_CHK_RK_SONICWAVE = gettick() + battle_config.K_DELAY_RK_SONICWAVE;

				sd->K_LOCK_RK_SONICWAVE = 0;
			}
			break;
		case RK_DEATHBOUND:
			if(DIFF_TICK(sd->K_CHK_RK_DEATHBOUND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_DEATHBOUND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_DEATHBOUND >= (battle_config.WOE_K_DELAY_RK_DEATHBOUND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_DEATHBOUND >= (battle_config.K_DELAY_RK_DEATHBOUND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_DEATHBOUND = sd->K_LOCK_RK_DEATHBOUND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_DEATHBOUND = gettick() + battle_config.WOE_K_DELAY_RK_DEATHBOUND;
				else
					sd->K_CHK_RK_DEATHBOUND = gettick() + battle_config.K_DELAY_RK_DEATHBOUND;

				sd->K_LOCK_RK_DEATHBOUND = 0;
			}
			break;
		case RK_HUNDREDSPEAR:
			if(DIFF_TICK(sd->K_CHK_RK_HUNDREDSPEAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_HUNDREDSPEAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_HUNDREDSPEAR >= (battle_config.WOE_K_DELAY_RK_HUNDREDSPEAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_HUNDREDSPEAR >= (battle_config.K_DELAY_RK_HUNDREDSPEAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_HUNDREDSPEAR = sd->K_LOCK_RK_HUNDREDSPEAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_HUNDREDSPEAR = gettick() + battle_config.WOE_K_DELAY_RK_HUNDREDSPEAR;
				else
					sd->K_CHK_RK_HUNDREDSPEAR = gettick() + battle_config.K_DELAY_RK_HUNDREDSPEAR;

				sd->K_LOCK_RK_HUNDREDSPEAR = 0;
			}
			break;
		case RK_WINDCUTTER:
			if(DIFF_TICK(sd->K_CHK_RK_WINDCUTTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_WINDCUTTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_WINDCUTTER >= (battle_config.WOE_K_DELAY_RK_WINDCUTTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_WINDCUTTER >= (battle_config.K_DELAY_RK_WINDCUTTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_WINDCUTTER = sd->K_LOCK_RK_WINDCUTTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_WINDCUTTER = gettick() + battle_config.WOE_K_DELAY_RK_WINDCUTTER;
				else
					sd->K_CHK_RK_WINDCUTTER = gettick() + battle_config.K_DELAY_RK_WINDCUTTER;

				sd->K_LOCK_RK_WINDCUTTER = 0;
			}
			break;
		case RK_IGNITIONBREAK:
			if(DIFF_TICK(sd->K_CHK_RK_IGNITIONBREAK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_IGNITIONBREAK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_IGNITIONBREAK >= (battle_config.WOE_K_DELAY_RK_IGNITIONBREAK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_IGNITIONBREAK >= (battle_config.K_DELAY_RK_IGNITIONBREAK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_IGNITIONBREAK = sd->K_LOCK_RK_IGNITIONBREAK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_IGNITIONBREAK = gettick() + battle_config.WOE_K_DELAY_RK_IGNITIONBREAK;
				else
					sd->K_CHK_RK_IGNITIONBREAK = gettick() + battle_config.K_DELAY_RK_IGNITIONBREAK;

				sd->K_LOCK_RK_IGNITIONBREAK = 0;
			}
			break;
		case RK_DRAGONBREATH:
			if(DIFF_TICK(sd->K_CHK_RK_DRAGONBREATH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_DRAGONBREATH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_DRAGONBREATH >= (battle_config.WOE_K_DELAY_RK_DRAGONBREATH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_DRAGONBREATH >= (battle_config.K_DELAY_RK_DRAGONBREATH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_DRAGONBREATH = sd->K_LOCK_RK_DRAGONBREATH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_DRAGONBREATH = gettick() + battle_config.WOE_K_DELAY_RK_DRAGONBREATH;
				else
					sd->K_CHK_RK_DRAGONBREATH = gettick() + battle_config.K_DELAY_RK_DRAGONBREATH;

				sd->K_LOCK_RK_DRAGONBREATH = 0;
			}
			break;
		case RK_CRUSHSTRIKE:
			if(DIFF_TICK(sd->K_CHK_RK_CRUSHSTRIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_CRUSHSTRIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_CRUSHSTRIKE >= (battle_config.WOE_K_DELAY_RK_CRUSHSTRIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_CRUSHSTRIKE >= (battle_config.K_DELAY_RK_CRUSHSTRIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_CRUSHSTRIKE = sd->K_LOCK_RK_CRUSHSTRIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_CRUSHSTRIKE = gettick() + battle_config.WOE_K_DELAY_RK_CRUSHSTRIKE;
				else
					sd->K_CHK_RK_CRUSHSTRIKE = gettick() + battle_config.K_DELAY_RK_CRUSHSTRIKE;

				sd->K_LOCK_RK_CRUSHSTRIKE = 0;
			}
			break;
		case RK_STORMBLAST:
			if(DIFF_TICK(sd->K_CHK_RK_STORMBLAST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_STORMBLAST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_STORMBLAST >= (battle_config.WOE_K_DELAY_RK_STORMBLAST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_STORMBLAST >= (battle_config.K_DELAY_RK_STORMBLAST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_STORMBLAST = sd->K_LOCK_RK_STORMBLAST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_STORMBLAST = gettick() + battle_config.WOE_K_DELAY_RK_STORMBLAST;
				else
					sd->K_CHK_RK_STORMBLAST = gettick() + battle_config.K_DELAY_RK_STORMBLAST;

				sd->K_LOCK_RK_STORMBLAST = 0;
			}
			break;
		case RK_PHANTOMTHRUST:
			if(DIFF_TICK(sd->K_CHK_RK_PHANTOMTHRUST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_PHANTOMTHRUST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_PHANTOMTHRUST >= (battle_config.WOE_K_DELAY_RK_PHANTOMTHRUST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_PHANTOMTHRUST >= (battle_config.K_DELAY_RK_PHANTOMTHRUST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_PHANTOMTHRUST = sd->K_LOCK_RK_PHANTOMTHRUST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_PHANTOMTHRUST = gettick() + battle_config.WOE_K_DELAY_RK_PHANTOMTHRUST;
				else
					sd->K_CHK_RK_PHANTOMTHRUST = gettick() + battle_config.K_DELAY_RK_PHANTOMTHRUST;

				sd->K_LOCK_RK_PHANTOMTHRUST = 0;
			}
			break;
		case GC_CROSSIMPACT:
			if(DIFF_TICK(sd->K_CHK_GC_CROSSIMPACT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GC_CROSSIMPACT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GC_CROSSIMPACT >= (battle_config.WOE_K_DELAY_GC_CROSSIMPACT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GC_CROSSIMPACT >= (battle_config.K_DELAY_GC_CROSSIMPACT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GC_CROSSIMPACT = sd->K_LOCK_GC_CROSSIMPACT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GC_CROSSIMPACT = gettick() + battle_config.WOE_K_DELAY_GC_CROSSIMPACT;
				else
					sd->K_CHK_GC_CROSSIMPACT = gettick() + battle_config.K_DELAY_GC_CROSSIMPACT;

				sd->K_LOCK_GC_CROSSIMPACT = 0;
			}
			break;
		case GC_WEAPONCRUSH:
			if(DIFF_TICK(sd->K_CHK_GC_WEAPONCRUSH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GC_WEAPONCRUSH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GC_WEAPONCRUSH >= (battle_config.WOE_K_DELAY_GC_WEAPONCRUSH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GC_WEAPONCRUSH >= (battle_config.K_DELAY_GC_WEAPONCRUSH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GC_WEAPONCRUSH = sd->K_LOCK_GC_WEAPONCRUSH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GC_WEAPONCRUSH = gettick() + battle_config.WOE_K_DELAY_GC_WEAPONCRUSH;
				else
					sd->K_CHK_GC_WEAPONCRUSH = gettick() + battle_config.K_DELAY_GC_WEAPONCRUSH;

				sd->K_LOCK_GC_WEAPONCRUSH = 0;
			}
			break;
		case GC_ROLLINGCUTTER:
			if(DIFF_TICK(sd->K_CHK_GC_ROLLINGCUTTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GC_ROLLINGCUTTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GC_ROLLINGCUTTER >= (battle_config.WOE_K_DELAY_GC_ROLLINGCUTTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GC_ROLLINGCUTTER >= (battle_config.K_DELAY_GC_ROLLINGCUTTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GC_ROLLINGCUTTER = sd->K_LOCK_GC_ROLLINGCUTTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GC_ROLLINGCUTTER = gettick() + battle_config.WOE_K_DELAY_GC_ROLLINGCUTTER;
				else
					sd->K_CHK_GC_ROLLINGCUTTER = gettick() + battle_config.K_DELAY_GC_ROLLINGCUTTER;

				sd->K_LOCK_GC_ROLLINGCUTTER = 0;
			}
			break;
		case GC_CROSSRIPPERSLASHER:
			if(DIFF_TICK(sd->K_CHK_GC_CROSSRIPPERSLASHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GC_CROSSRIPPERSLASHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GC_CROSSRIPPERSLASHER >= (battle_config.WOE_K_DELAY_GC_CROSSRIPPERSLASHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GC_CROSSRIPPERSLASHER >= (battle_config.K_DELAY_GC_CROSSRIPPERSLASHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GC_CROSSRIPPERSLASHER = sd->K_LOCK_GC_CROSSRIPPERSLASHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GC_CROSSRIPPERSLASHER = gettick() + battle_config.WOE_K_DELAY_GC_CROSSRIPPERSLASHER;
				else
					sd->K_CHK_GC_CROSSRIPPERSLASHER = gettick() + battle_config.K_DELAY_GC_CROSSRIPPERSLASHER;

				sd->K_LOCK_GC_CROSSRIPPERSLASHER = 0;
			}
			break;
		case AB_JUDEX:
			if(DIFF_TICK(sd->K_CHK_AB_JUDEX,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_JUDEX - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_JUDEX >= (battle_config.WOE_K_DELAY_AB_JUDEX/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_JUDEX >= (battle_config.K_DELAY_AB_JUDEX/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_JUDEX = sd->K_LOCK_AB_JUDEX +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_JUDEX = gettick() + battle_config.WOE_K_DELAY_AB_JUDEX;
				else
					sd->K_CHK_AB_JUDEX = gettick() + battle_config.K_DELAY_AB_JUDEX;

				sd->K_LOCK_AB_JUDEX = 0;
			}
			break;
		case AB_ADORAMUS:
			if(DIFF_TICK(sd->K_CHK_AB_ADORAMUS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_ADORAMUS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_ADORAMUS >= (battle_config.WOE_K_DELAY_AB_ADORAMUS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_ADORAMUS >= (battle_config.K_DELAY_AB_ADORAMUS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_ADORAMUS = sd->K_LOCK_AB_ADORAMUS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_ADORAMUS = gettick() + battle_config.WOE_K_DELAY_AB_ADORAMUS;
				else
					sd->K_CHK_AB_ADORAMUS = gettick() + battle_config.K_DELAY_AB_ADORAMUS;

				sd->K_LOCK_AB_ADORAMUS = 0;
			}
			break;
		case AB_CHEAL:
			if(DIFF_TICK(sd->K_CHK_AB_CHEAL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_CHEAL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_CHEAL >= (battle_config.WOE_K_DELAY_AB_CHEAL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_CHEAL >= (battle_config.K_DELAY_AB_CHEAL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_CHEAL = sd->K_LOCK_AB_CHEAL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_CHEAL = gettick() + battle_config.WOE_K_DELAY_AB_CHEAL;
				else
					sd->K_CHK_AB_CHEAL = gettick() + battle_config.K_DELAY_AB_CHEAL;

				sd->K_LOCK_AB_CHEAL = 0;
			}
			break;
		case AB_EPICLESIS:
			if(DIFF_TICK(sd->K_CHK_AB_EPICLESIS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_EPICLESIS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_EPICLESIS >= (battle_config.WOE_K_DELAY_AB_EPICLESIS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_EPICLESIS >= (battle_config.K_DELAY_AB_EPICLESIS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_EPICLESIS = sd->K_LOCK_AB_EPICLESIS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_EPICLESIS = gettick() + battle_config.WOE_K_DELAY_AB_EPICLESIS;
				else
					sd->K_CHK_AB_EPICLESIS = gettick() + battle_config.K_DELAY_AB_EPICLESIS;

				sd->K_LOCK_AB_EPICLESIS = 0;
			}
			break;
		case AB_PRAEFATIO:
			if(DIFF_TICK(sd->K_CHK_AB_PRAEFATIO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_PRAEFATIO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_PRAEFATIO >= (battle_config.WOE_K_DELAY_AB_PRAEFATIO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_PRAEFATIO >= (battle_config.K_DELAY_AB_PRAEFATIO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_PRAEFATIO = sd->K_LOCK_AB_PRAEFATIO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_PRAEFATIO = gettick() + battle_config.WOE_K_DELAY_AB_PRAEFATIO;
				else
					sd->K_CHK_AB_PRAEFATIO = gettick() + battle_config.K_DELAY_AB_PRAEFATIO;

				sd->K_LOCK_AB_PRAEFATIO = 0;
			}
			break;
		case AB_EUCHARISTICA:
			if(DIFF_TICK(sd->K_CHK_AB_EUCHARISTICA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_EUCHARISTICA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_EUCHARISTICA >= (battle_config.WOE_K_DELAY_AB_EUCHARISTICA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_EUCHARISTICA >= (battle_config.K_DELAY_AB_EUCHARISTICA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_EUCHARISTICA = sd->K_LOCK_AB_EUCHARISTICA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_EUCHARISTICA = gettick() + battle_config.WOE_K_DELAY_AB_EUCHARISTICA;
				else
					sd->K_CHK_AB_EUCHARISTICA = gettick() + battle_config.K_DELAY_AB_EUCHARISTICA;

				sd->K_LOCK_AB_EUCHARISTICA = 0;
			}
			break;
		case AB_RENOVATIO:
			if(DIFF_TICK(sd->K_CHK_AB_RENOVATIO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_RENOVATIO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_RENOVATIO >= (battle_config.WOE_K_DELAY_AB_RENOVATIO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_RENOVATIO >= (battle_config.K_DELAY_AB_RENOVATIO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_RENOVATIO = sd->K_LOCK_AB_RENOVATIO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_RENOVATIO = gettick() + battle_config.WOE_K_DELAY_AB_RENOVATIO;
				else
					sd->K_CHK_AB_RENOVATIO = gettick() + battle_config.K_DELAY_AB_RENOVATIO;

				sd->K_LOCK_AB_RENOVATIO = 0;
			}
			break;
		case AB_HIGHNESSHEAL:
			if(DIFF_TICK(sd->K_CHK_AB_HIGHNESSHEAL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_HIGHNESSHEAL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_HIGHNESSHEAL >= (battle_config.WOE_K_DELAY_AB_HIGHNESSHEAL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_HIGHNESSHEAL >= (battle_config.K_DELAY_AB_HIGHNESSHEAL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_HIGHNESSHEAL = sd->K_LOCK_AB_HIGHNESSHEAL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_HIGHNESSHEAL = gettick() + battle_config.WOE_K_DELAY_AB_HIGHNESSHEAL;
				else
					sd->K_CHK_AB_HIGHNESSHEAL = gettick() + battle_config.K_DELAY_AB_HIGHNESSHEAL;

				sd->K_LOCK_AB_HIGHNESSHEAL = 0;
			}
			break;
		case AB_CLEARANCE:
			if(DIFF_TICK(sd->K_CHK_AB_CLEARANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_CLEARANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_CLEARANCE >= (battle_config.WOE_K_DELAY_AB_CLEARANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_CLEARANCE >= (battle_config.K_DELAY_AB_CLEARANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_CLEARANCE = sd->K_LOCK_AB_CLEARANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_CLEARANCE = gettick() + battle_config.WOE_K_DELAY_AB_CLEARANCE;
				else
					sd->K_CHK_AB_CLEARANCE = gettick() + battle_config.K_DELAY_AB_CLEARANCE;

				sd->K_LOCK_AB_CLEARANCE = 0;
			}
			break;
		case AB_EXPIATIO:
			if(DIFF_TICK(sd->K_CHK_AB_EXPIATIO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_EXPIATIO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_EXPIATIO >= (battle_config.WOE_K_DELAY_AB_EXPIATIO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_EXPIATIO >= (battle_config.K_DELAY_AB_EXPIATIO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_EXPIATIO = sd->K_LOCK_AB_EXPIATIO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_EXPIATIO = gettick() + battle_config.WOE_K_DELAY_AB_EXPIATIO;
				else
					sd->K_CHK_AB_EXPIATIO = gettick() + battle_config.K_DELAY_AB_EXPIATIO;

				sd->K_LOCK_AB_EXPIATIO = 0;
			}
			break;
		case AB_DUPLELIGHT:
			if(DIFF_TICK(sd->K_CHK_AB_DUPLELIGHT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_DUPLELIGHT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_DUPLELIGHT >= (battle_config.WOE_K_DELAY_AB_DUPLELIGHT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_DUPLELIGHT >= (battle_config.K_DELAY_AB_DUPLELIGHT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_DUPLELIGHT = sd->K_LOCK_AB_DUPLELIGHT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_DUPLELIGHT = gettick() + battle_config.WOE_K_DELAY_AB_DUPLELIGHT;
				else
					sd->K_CHK_AB_DUPLELIGHT = gettick() + battle_config.K_DELAY_AB_DUPLELIGHT;

				sd->K_LOCK_AB_DUPLELIGHT = 0;
			}
			break;
		case AB_DUPLELIGHT_MELEE:
			if(DIFF_TICK(sd->K_CHK_AB_DUPLELIGHT_MELEE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_DUPLELIGHT_MELEE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_DUPLELIGHT_MELEE >= (battle_config.WOE_K_DELAY_AB_DUPLELIGHT_MELEE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_DUPLELIGHT_MELEE >= (battle_config.K_DELAY_AB_DUPLELIGHT_MELEE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_DUPLELIGHT_MELEE = sd->K_LOCK_AB_DUPLELIGHT_MELEE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_DUPLELIGHT_MELEE = gettick() + battle_config.WOE_K_DELAY_AB_DUPLELIGHT_MELEE;
				else
					sd->K_CHK_AB_DUPLELIGHT_MELEE = gettick() + battle_config.K_DELAY_AB_DUPLELIGHT_MELEE;

				sd->K_LOCK_AB_DUPLELIGHT_MELEE = 0;
			}
			break;
		case AB_DUPLELIGHT_MAGIC:
			if(DIFF_TICK(sd->K_CHK_AB_DUPLELIGHT_MAGIC,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_DUPLELIGHT_MAGIC - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_DUPLELIGHT_MAGIC >= (battle_config.WOE_K_DELAY_AB_DUPLELIGHT_MAGIC/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_DUPLELIGHT_MAGIC >= (battle_config.K_DELAY_AB_DUPLELIGHT_MAGIC/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_DUPLELIGHT_MAGIC = sd->K_LOCK_AB_DUPLELIGHT_MAGIC +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_DUPLELIGHT_MAGIC = gettick() + battle_config.WOE_K_DELAY_AB_DUPLELIGHT_MAGIC;
				else
					sd->K_CHK_AB_DUPLELIGHT_MAGIC = gettick() + battle_config.K_DELAY_AB_DUPLELIGHT_MAGIC;

				sd->K_LOCK_AB_DUPLELIGHT_MAGIC = 0;
			}
			break;
		case AB_SILENTIUM:
			if(DIFF_TICK(sd->K_CHK_AB_SILENTIUM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_SILENTIUM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_SILENTIUM >= (battle_config.WOE_K_DELAY_AB_SILENTIUM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_SILENTIUM >= (battle_config.K_DELAY_AB_SILENTIUM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_SILENTIUM = sd->K_LOCK_AB_SILENTIUM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_SILENTIUM = gettick() + battle_config.WOE_K_DELAY_AB_SILENTIUM;
				else
					sd->K_CHK_AB_SILENTIUM = gettick() + battle_config.K_DELAY_AB_SILENTIUM;

				sd->K_LOCK_AB_SILENTIUM = 0;
			}
			break;
		case WL_WHITEIMPRISON:
			if(DIFF_TICK(sd->K_CHK_WL_WHITEIMPRISON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_WHITEIMPRISON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_WHITEIMPRISON >= (battle_config.WOE_K_DELAY_WL_WHITEIMPRISON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_WHITEIMPRISON >= (battle_config.K_DELAY_WL_WHITEIMPRISON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_WHITEIMPRISON = sd->K_LOCK_WL_WHITEIMPRISON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_WHITEIMPRISON = gettick() + battle_config.WOE_K_DELAY_WL_WHITEIMPRISON;
				else
					sd->K_CHK_WL_WHITEIMPRISON = gettick() + battle_config.K_DELAY_WL_WHITEIMPRISON;

				sd->K_LOCK_WL_WHITEIMPRISON = 0;
			}
			break;
		case WL_SOULEXPANSION:
			if(DIFF_TICK(sd->K_CHK_WL_SOULEXPANSION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_SOULEXPANSION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_SOULEXPANSION >= (battle_config.WOE_K_DELAY_WL_SOULEXPANSION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_SOULEXPANSION >= (battle_config.K_DELAY_WL_SOULEXPANSION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_SOULEXPANSION = sd->K_LOCK_WL_SOULEXPANSION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_SOULEXPANSION = gettick() + battle_config.WOE_K_DELAY_WL_SOULEXPANSION;
				else
					sd->K_CHK_WL_SOULEXPANSION = gettick() + battle_config.K_DELAY_WL_SOULEXPANSION;

				sd->K_LOCK_WL_SOULEXPANSION = 0;
			}
			break;
		case WL_FROSTMISTY:
			if(DIFF_TICK(sd->K_CHK_WL_FROSTMISTY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_FROSTMISTY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_FROSTMISTY >= (battle_config.WOE_K_DELAY_WL_FROSTMISTY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_FROSTMISTY >= (battle_config.K_DELAY_WL_FROSTMISTY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_FROSTMISTY = sd->K_LOCK_WL_FROSTMISTY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_FROSTMISTY = gettick() + battle_config.WOE_K_DELAY_WL_FROSTMISTY;
				else
					sd->K_CHK_WL_FROSTMISTY = gettick() + battle_config.K_DELAY_WL_FROSTMISTY;

				sd->K_LOCK_WL_FROSTMISTY = 0;
			}
			break;
		case WL_JACKFROST:
			if(DIFF_TICK(sd->K_CHK_WL_JACKFROST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_JACKFROST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_JACKFROST >= (battle_config.WOE_K_DELAY_WL_JACKFROST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_JACKFROST >= (battle_config.K_DELAY_WL_JACKFROST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_JACKFROST = sd->K_LOCK_WL_JACKFROST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_JACKFROST = gettick() + battle_config.WOE_K_DELAY_WL_JACKFROST;
				else
					sd->K_CHK_WL_JACKFROST = gettick() + battle_config.K_DELAY_WL_JACKFROST;

				sd->K_LOCK_WL_JACKFROST = 0;
			}
			break;
		case WL_MARSHOFABYSS:
			if(DIFF_TICK(sd->K_CHK_WL_MARSHOFABYSS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_MARSHOFABYSS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_MARSHOFABYSS >= (battle_config.WOE_K_DELAY_WL_MARSHOFABYSS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_MARSHOFABYSS >= (battle_config.K_DELAY_WL_MARSHOFABYSS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_MARSHOFABYSS = sd->K_LOCK_WL_MARSHOFABYSS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_MARSHOFABYSS = gettick() + battle_config.WOE_K_DELAY_WL_MARSHOFABYSS;
				else
					sd->K_CHK_WL_MARSHOFABYSS = gettick() + battle_config.K_DELAY_WL_MARSHOFABYSS;

				sd->K_LOCK_WL_MARSHOFABYSS = 0;
			}
			break;
		case WL_RADIUS:
			if(DIFF_TICK(sd->K_CHK_WL_RADIUS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_RADIUS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_RADIUS >= (battle_config.WOE_K_DELAY_WL_RADIUS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_RADIUS >= (battle_config.K_DELAY_WL_RADIUS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_RADIUS = sd->K_LOCK_WL_RADIUS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_RADIUS = gettick() + battle_config.WOE_K_DELAY_WL_RADIUS;
				else
					sd->K_CHK_WL_RADIUS = gettick() + battle_config.K_DELAY_WL_RADIUS;

				sd->K_LOCK_WL_RADIUS = 0;
			}
			break;
		case WL_STASIS:
			if(DIFF_TICK(sd->K_CHK_WL_STASIS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_STASIS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_STASIS >= (battle_config.WOE_K_DELAY_WL_STASIS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_STASIS >= (battle_config.K_DELAY_WL_STASIS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_STASIS = sd->K_LOCK_WL_STASIS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_STASIS = gettick() + battle_config.WOE_K_DELAY_WL_STASIS;
				else
					sd->K_CHK_WL_STASIS = gettick() + battle_config.K_DELAY_WL_STASIS;

				sd->K_LOCK_WL_STASIS = 0;
			}
			break;
		case WL_DRAINLIFE:
			if(DIFF_TICK(sd->K_CHK_WL_DRAINLIFE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_DRAINLIFE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_DRAINLIFE >= (battle_config.WOE_K_DELAY_WL_DRAINLIFE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_DRAINLIFE >= (battle_config.K_DELAY_WL_DRAINLIFE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_DRAINLIFE = sd->K_LOCK_WL_DRAINLIFE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_DRAINLIFE = gettick() + battle_config.WOE_K_DELAY_WL_DRAINLIFE;
				else
					sd->K_CHK_WL_DRAINLIFE = gettick() + battle_config.K_DELAY_WL_DRAINLIFE;

				sd->K_LOCK_WL_DRAINLIFE = 0;
			}
			break;
		case WL_CRIMSONROCK:
			if(DIFF_TICK(sd->K_CHK_WL_CRIMSONROCK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_CRIMSONROCK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_CRIMSONROCK >= (battle_config.WOE_K_DELAY_WL_CRIMSONROCK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_CRIMSONROCK >= (battle_config.K_DELAY_WL_CRIMSONROCK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_CRIMSONROCK = sd->K_LOCK_WL_CRIMSONROCK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_CRIMSONROCK = gettick() + battle_config.WOE_K_DELAY_WL_CRIMSONROCK;
				else
					sd->K_CHK_WL_CRIMSONROCK = gettick() + battle_config.K_DELAY_WL_CRIMSONROCK;

				sd->K_LOCK_WL_CRIMSONROCK = 0;
			}
			break;
		case WL_HELLINFERNO:
			if(DIFF_TICK(sd->K_CHK_WL_HELLINFERNO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_HELLINFERNO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_HELLINFERNO >= (battle_config.WOE_K_DELAY_WL_HELLINFERNO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_HELLINFERNO >= (battle_config.K_DELAY_WL_HELLINFERNO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_HELLINFERNO = sd->K_LOCK_WL_HELLINFERNO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_HELLINFERNO = gettick() + battle_config.WOE_K_DELAY_WL_HELLINFERNO;
				else
					sd->K_CHK_WL_HELLINFERNO = gettick() + battle_config.K_DELAY_WL_HELLINFERNO;

				sd->K_LOCK_WL_HELLINFERNO = 0;
			}
			break;
		case WL_COMET:
			if(DIFF_TICK(sd->K_CHK_WL_COMET,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_COMET - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_COMET >= (battle_config.WOE_K_DELAY_WL_COMET/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_COMET >= (battle_config.K_DELAY_WL_COMET/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_COMET = sd->K_LOCK_WL_COMET +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_COMET = gettick() + battle_config.WOE_K_DELAY_WL_COMET;
				else
					sd->K_CHK_WL_COMET = gettick() + battle_config.K_DELAY_WL_COMET;

				sd->K_LOCK_WL_COMET = 0;
			}
			break;
		case WL_CHAINLIGHTNING:
			if(DIFF_TICK(sd->K_CHK_WL_CHAINLIGHTNING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_CHAINLIGHTNING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_CHAINLIGHTNING >= (battle_config.WOE_K_DELAY_WL_CHAINLIGHTNING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_CHAINLIGHTNING >= (battle_config.K_DELAY_WL_CHAINLIGHTNING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_CHAINLIGHTNING = sd->K_LOCK_WL_CHAINLIGHTNING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_CHAINLIGHTNING = gettick() + battle_config.WOE_K_DELAY_WL_CHAINLIGHTNING;
				else
					sd->K_CHK_WL_CHAINLIGHTNING = gettick() + battle_config.K_DELAY_WL_CHAINLIGHTNING;

				sd->K_LOCK_WL_CHAINLIGHTNING = 0;
			}
			break;
		case WL_CHAINLIGHTNING_ATK:
			if(DIFF_TICK(sd->K_CHK_WL_CHAINLIGHTNING_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_CHAINLIGHTNING_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_CHAINLIGHTNING_ATK >= (battle_config.WOE_K_DELAY_WL_CHAINLIGHTNING_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_CHAINLIGHTNING_ATK >= (battle_config.K_DELAY_WL_CHAINLIGHTNING_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_CHAINLIGHTNING_ATK = sd->K_LOCK_WL_CHAINLIGHTNING_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_CHAINLIGHTNING_ATK = gettick() + battle_config.WOE_K_DELAY_WL_CHAINLIGHTNING_ATK;
				else
					sd->K_CHK_WL_CHAINLIGHTNING_ATK = gettick() + battle_config.K_DELAY_WL_CHAINLIGHTNING_ATK;

				sd->K_LOCK_WL_CHAINLIGHTNING_ATK = 0;
			}
			break;
		case WL_EARTHSTRAIN:
			if(DIFF_TICK(sd->K_CHK_WL_EARTHSTRAIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_EARTHSTRAIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_EARTHSTRAIN >= (battle_config.WOE_K_DELAY_WL_EARTHSTRAIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_EARTHSTRAIN >= (battle_config.K_DELAY_WL_EARTHSTRAIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_EARTHSTRAIN = sd->K_LOCK_WL_EARTHSTRAIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_EARTHSTRAIN = gettick() + battle_config.WOE_K_DELAY_WL_EARTHSTRAIN;
				else
					sd->K_CHK_WL_EARTHSTRAIN = gettick() + battle_config.K_DELAY_WL_EARTHSTRAIN;

				sd->K_LOCK_WL_EARTHSTRAIN = 0;
			}
			break;
		case WL_TETRAVORTEX:
			if(DIFF_TICK(sd->K_CHK_WL_TETRAVORTEX,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TETRAVORTEX - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TETRAVORTEX >= (battle_config.WOE_K_DELAY_WL_TETRAVORTEX/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TETRAVORTEX >= (battle_config.K_DELAY_WL_TETRAVORTEX/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TETRAVORTEX = sd->K_LOCK_WL_TETRAVORTEX +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TETRAVORTEX = gettick() + battle_config.WOE_K_DELAY_WL_TETRAVORTEX;
				else
					sd->K_CHK_WL_TETRAVORTEX = gettick() + battle_config.K_DELAY_WL_TETRAVORTEX;

				sd->K_LOCK_WL_TETRAVORTEX = 0;
			}
			break;
		case WL_TETRAVORTEX_FIRE:
			if(DIFF_TICK(sd->K_CHK_WL_TETRAVORTEX_FIRE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TETRAVORTEX_FIRE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TETRAVORTEX_FIRE >= (battle_config.WOE_K_DELAY_WL_TETRAVORTEX_FIRE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TETRAVORTEX_FIRE >= (battle_config.K_DELAY_WL_TETRAVORTEX_FIRE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TETRAVORTEX_FIRE = sd->K_LOCK_WL_TETRAVORTEX_FIRE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TETRAVORTEX_FIRE = gettick() + battle_config.WOE_K_DELAY_WL_TETRAVORTEX_FIRE;
				else
					sd->K_CHK_WL_TETRAVORTEX_FIRE = gettick() + battle_config.K_DELAY_WL_TETRAVORTEX_FIRE;

				sd->K_LOCK_WL_TETRAVORTEX_FIRE = 0;
			}
			break;
		case WL_TETRAVORTEX_WATER:
			if(DIFF_TICK(sd->K_CHK_WL_TETRAVORTEX_WATER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TETRAVORTEX_WATER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TETRAVORTEX_WATER >= (battle_config.WOE_K_DELAY_WL_TETRAVORTEX_WATER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TETRAVORTEX_WATER >= (battle_config.K_DELAY_WL_TETRAVORTEX_WATER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TETRAVORTEX_WATER = sd->K_LOCK_WL_TETRAVORTEX_WATER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TETRAVORTEX_WATER = gettick() + battle_config.WOE_K_DELAY_WL_TETRAVORTEX_WATER;
				else
					sd->K_CHK_WL_TETRAVORTEX_WATER = gettick() + battle_config.K_DELAY_WL_TETRAVORTEX_WATER;

				sd->K_LOCK_WL_TETRAVORTEX_WATER = 0;
			}
			break;
		case WL_TETRAVORTEX_WIND:
			if(DIFF_TICK(sd->K_CHK_WL_TETRAVORTEX_WIND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TETRAVORTEX_WIND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TETRAVORTEX_WIND >= (battle_config.WOE_K_DELAY_WL_TETRAVORTEX_WIND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TETRAVORTEX_WIND >= (battle_config.K_DELAY_WL_TETRAVORTEX_WIND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TETRAVORTEX_WIND = sd->K_LOCK_WL_TETRAVORTEX_WIND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TETRAVORTEX_WIND = gettick() + battle_config.WOE_K_DELAY_WL_TETRAVORTEX_WIND;
				else
					sd->K_CHK_WL_TETRAVORTEX_WIND = gettick() + battle_config.K_DELAY_WL_TETRAVORTEX_WIND;

				sd->K_LOCK_WL_TETRAVORTEX_WIND = 0;
			}
			break;
		case WL_TETRAVORTEX_GROUND:
			if(DIFF_TICK(sd->K_CHK_WL_TETRAVORTEX_GROUND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TETRAVORTEX_GROUND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TETRAVORTEX_GROUND >= (battle_config.WOE_K_DELAY_WL_TETRAVORTEX_GROUND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TETRAVORTEX_GROUND >= (battle_config.K_DELAY_WL_TETRAVORTEX_GROUND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TETRAVORTEX_GROUND = sd->K_LOCK_WL_TETRAVORTEX_GROUND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TETRAVORTEX_GROUND = gettick() + battle_config.WOE_K_DELAY_WL_TETRAVORTEX_GROUND;
				else
					sd->K_CHK_WL_TETRAVORTEX_GROUND = gettick() + battle_config.K_DELAY_WL_TETRAVORTEX_GROUND;

				sd->K_LOCK_WL_TETRAVORTEX_GROUND = 0;
			}
			break;
		case WL_RELEASE:
			if(DIFF_TICK(sd->K_CHK_WL_RELEASE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_RELEASE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_RELEASE >= (battle_config.WOE_K_DELAY_WL_RELEASE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_RELEASE >= (battle_config.K_DELAY_WL_RELEASE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_RELEASE = sd->K_LOCK_WL_RELEASE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_RELEASE = gettick() + battle_config.WOE_K_DELAY_WL_RELEASE;
				else
					sd->K_CHK_WL_RELEASE = gettick() + battle_config.K_DELAY_WL_RELEASE;

				sd->K_LOCK_WL_RELEASE = 0;
			}
			break;
		case WL_READING_SB:
			if(DIFF_TICK(sd->K_CHK_WL_READING_SB,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_READING_SB - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_READING_SB >= (battle_config.WOE_K_DELAY_WL_READING_SB/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_READING_SB >= (battle_config.K_DELAY_WL_READING_SB/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_READING_SB = sd->K_LOCK_WL_READING_SB +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_READING_SB = gettick() + battle_config.WOE_K_DELAY_WL_READING_SB;
				else
					sd->K_CHK_WL_READING_SB = gettick() + battle_config.K_DELAY_WL_READING_SB;

				sd->K_LOCK_WL_READING_SB = 0;
			}
			break;
		case WL_FREEZE_SP:
			if(DIFF_TICK(sd->K_CHK_WL_FREEZE_SP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_FREEZE_SP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_FREEZE_SP >= (battle_config.WOE_K_DELAY_WL_FREEZE_SP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_FREEZE_SP >= (battle_config.K_DELAY_WL_FREEZE_SP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_FREEZE_SP = sd->K_LOCK_WL_FREEZE_SP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_FREEZE_SP = gettick() + battle_config.WOE_K_DELAY_WL_FREEZE_SP;
				else
					sd->K_CHK_WL_FREEZE_SP = gettick() + battle_config.K_DELAY_WL_FREEZE_SP;

				sd->K_LOCK_WL_FREEZE_SP = 0;
			}
			break;
		case RA_ARROWSTORM:
			if(DIFF_TICK(sd->K_CHK_RA_ARROWSTORM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RA_ARROWSTORM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RA_ARROWSTORM >= (battle_config.WOE_K_DELAY_RA_ARROWSTORM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RA_ARROWSTORM >= (battle_config.K_DELAY_RA_ARROWSTORM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RA_ARROWSTORM = sd->K_LOCK_RA_ARROWSTORM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RA_ARROWSTORM = gettick() + battle_config.WOE_K_DELAY_RA_ARROWSTORM;
				else
					sd->K_CHK_RA_ARROWSTORM = gettick() + battle_config.K_DELAY_RA_ARROWSTORM;

				sd->K_LOCK_RA_ARROWSTORM = 0;
			}
			break;
		case RA_AIMEDBOLT:
			if(DIFF_TICK(sd->K_CHK_RA_AIMEDBOLT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RA_AIMEDBOLT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RA_AIMEDBOLT >= (battle_config.WOE_K_DELAY_RA_AIMEDBOLT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RA_AIMEDBOLT >= (battle_config.K_DELAY_RA_AIMEDBOLT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RA_AIMEDBOLT = sd->K_LOCK_RA_AIMEDBOLT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RA_AIMEDBOLT = gettick() + battle_config.WOE_K_DELAY_RA_AIMEDBOLT;
				else
					sd->K_CHK_RA_AIMEDBOLT = gettick() + battle_config.K_DELAY_RA_AIMEDBOLT;

				sd->K_LOCK_RA_AIMEDBOLT = 0;
			}
			break;
		case RA_WUGSTRIKE:
			if(DIFF_TICK(sd->K_CHK_RA_WUGSTRIKE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RA_WUGSTRIKE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RA_WUGSTRIKE >= (battle_config.WOE_K_DELAY_RA_WUGSTRIKE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RA_WUGSTRIKE >= (battle_config.K_DELAY_RA_WUGSTRIKE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RA_WUGSTRIKE = sd->K_LOCK_RA_WUGSTRIKE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RA_WUGSTRIKE = gettick() + battle_config.WOE_K_DELAY_RA_WUGSTRIKE;
				else
					sd->K_CHK_RA_WUGSTRIKE = gettick() + battle_config.K_DELAY_RA_WUGSTRIKE;

				sd->K_LOCK_RA_WUGSTRIKE = 0;
			}
			break;
		case RA_WUGBITE:
			if(DIFF_TICK(sd->K_CHK_RA_WUGBITE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RA_WUGBITE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RA_WUGBITE >= (battle_config.WOE_K_DELAY_RA_WUGBITE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RA_WUGBITE >= (battle_config.K_DELAY_RA_WUGBITE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RA_WUGBITE = sd->K_LOCK_RA_WUGBITE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RA_WUGBITE = gettick() + battle_config.WOE_K_DELAY_RA_WUGBITE;
				else
					sd->K_CHK_RA_WUGBITE = gettick() + battle_config.K_DELAY_RA_WUGBITE;

				sd->K_LOCK_RA_WUGBITE = 0;
			}
			break;
		case NC_BOOSTKNUCKLE:
			if(DIFF_TICK(sd->K_CHK_NC_BOOSTKNUCKLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_BOOSTKNUCKLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_BOOSTKNUCKLE >= (battle_config.WOE_K_DELAY_NC_BOOSTKNUCKLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_BOOSTKNUCKLE >= (battle_config.K_DELAY_NC_BOOSTKNUCKLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_BOOSTKNUCKLE = sd->K_LOCK_NC_BOOSTKNUCKLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_BOOSTKNUCKLE = gettick() + battle_config.WOE_K_DELAY_NC_BOOSTKNUCKLE;
				else
					sd->K_CHK_NC_BOOSTKNUCKLE = gettick() + battle_config.K_DELAY_NC_BOOSTKNUCKLE;

				sd->K_LOCK_NC_BOOSTKNUCKLE = 0;
			}
			break;
		case NC_PILEBUNKER:
			if(DIFF_TICK(sd->K_CHK_NC_PILEBUNKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_PILEBUNKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_PILEBUNKER >= (battle_config.WOE_K_DELAY_NC_PILEBUNKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_PILEBUNKER >= (battle_config.K_DELAY_NC_PILEBUNKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_PILEBUNKER = sd->K_LOCK_NC_PILEBUNKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_PILEBUNKER = gettick() + battle_config.WOE_K_DELAY_NC_PILEBUNKER;
				else
					sd->K_CHK_NC_PILEBUNKER = gettick() + battle_config.K_DELAY_NC_PILEBUNKER;

				sd->K_LOCK_NC_PILEBUNKER = 0;
			}
			break;
		case NC_VULCANARM:
			if(DIFF_TICK(sd->K_CHK_NC_VULCANARM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_VULCANARM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_VULCANARM >= (battle_config.WOE_K_DELAY_NC_VULCANARM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_VULCANARM >= (battle_config.K_DELAY_NC_VULCANARM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_VULCANARM = sd->K_LOCK_NC_VULCANARM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_VULCANARM = gettick() + battle_config.WOE_K_DELAY_NC_VULCANARM;
				else
					sd->K_CHK_NC_VULCANARM = gettick() + battle_config.K_DELAY_NC_VULCANARM;

				sd->K_LOCK_NC_VULCANARM = 0;
			}
			break;
		case NC_FLAMELAUNCHER:
			if(DIFF_TICK(sd->K_CHK_NC_FLAMELAUNCHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_FLAMELAUNCHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_FLAMELAUNCHER >= (battle_config.WOE_K_DELAY_NC_FLAMELAUNCHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_FLAMELAUNCHER >= (battle_config.K_DELAY_NC_FLAMELAUNCHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_FLAMELAUNCHER = sd->K_LOCK_NC_FLAMELAUNCHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_FLAMELAUNCHER = gettick() + battle_config.WOE_K_DELAY_NC_FLAMELAUNCHER;
				else
					sd->K_CHK_NC_FLAMELAUNCHER = gettick() + battle_config.K_DELAY_NC_FLAMELAUNCHER;

				sd->K_LOCK_NC_FLAMELAUNCHER = 0;
			}
			break;
		case NC_COLDSLOWER:
			if(DIFF_TICK(sd->K_CHK_NC_COLDSLOWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_COLDSLOWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_COLDSLOWER >= (battle_config.WOE_K_DELAY_NC_COLDSLOWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_COLDSLOWER >= (battle_config.K_DELAY_NC_COLDSLOWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_COLDSLOWER = sd->K_LOCK_NC_COLDSLOWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_COLDSLOWER = gettick() + battle_config.WOE_K_DELAY_NC_COLDSLOWER;
				else
					sd->K_CHK_NC_COLDSLOWER = gettick() + battle_config.K_DELAY_NC_COLDSLOWER;

				sd->K_LOCK_NC_COLDSLOWER = 0;
			}
			break;
		case NC_ARMSCANNON:
			if(DIFF_TICK(sd->K_CHK_NC_ARMSCANNON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_ARMSCANNON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_ARMSCANNON >= (battle_config.WOE_K_DELAY_NC_ARMSCANNON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_ARMSCANNON >= (battle_config.K_DELAY_NC_ARMSCANNON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_ARMSCANNON = sd->K_LOCK_NC_ARMSCANNON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_ARMSCANNON = gettick() + battle_config.WOE_K_DELAY_NC_ARMSCANNON;
				else
					sd->K_CHK_NC_ARMSCANNON = gettick() + battle_config.K_DELAY_NC_ARMSCANNON;

				sd->K_LOCK_NC_ARMSCANNON = 0;
			}
			break;
		case NC_ACCELERATION:
			if(DIFF_TICK(sd->K_CHK_NC_ACCELERATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_ACCELERATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_ACCELERATION >= (battle_config.WOE_K_DELAY_NC_ACCELERATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_ACCELERATION >= (battle_config.K_DELAY_NC_ACCELERATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_ACCELERATION = sd->K_LOCK_NC_ACCELERATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_ACCELERATION = gettick() + battle_config.WOE_K_DELAY_NC_ACCELERATION;
				else
					sd->K_CHK_NC_ACCELERATION = gettick() + battle_config.K_DELAY_NC_ACCELERATION;

				sd->K_LOCK_NC_ACCELERATION = 0;
			}
			break;
		case NC_F_SIDESLIDE:
			if(DIFF_TICK(sd->K_CHK_NC_F_SIDESLIDE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_F_SIDESLIDE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_F_SIDESLIDE >= (battle_config.WOE_K_DELAY_NC_F_SIDESLIDE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_F_SIDESLIDE >= (battle_config.K_DELAY_NC_F_SIDESLIDE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_F_SIDESLIDE = sd->K_LOCK_NC_F_SIDESLIDE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_F_SIDESLIDE = gettick() + battle_config.WOE_K_DELAY_NC_F_SIDESLIDE;
				else
					sd->K_CHK_NC_F_SIDESLIDE = gettick() + battle_config.K_DELAY_NC_F_SIDESLIDE;

				sd->K_LOCK_NC_F_SIDESLIDE = 0;
			}
			break;
		case NC_B_SIDESLIDE:
			if(DIFF_TICK(sd->K_CHK_NC_B_SIDESLIDE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_B_SIDESLIDE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_B_SIDESLIDE >= (battle_config.WOE_K_DELAY_NC_B_SIDESLIDE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_B_SIDESLIDE >= (battle_config.K_DELAY_NC_B_SIDESLIDE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_B_SIDESLIDE = sd->K_LOCK_NC_B_SIDESLIDE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_B_SIDESLIDE = gettick() + battle_config.WOE_K_DELAY_NC_B_SIDESLIDE;
				else
					sd->K_CHK_NC_B_SIDESLIDE = gettick() + battle_config.K_DELAY_NC_B_SIDESLIDE;

				sd->K_LOCK_NC_B_SIDESLIDE = 0;
			}
			break;
		case NC_MAINFRAME:
			if(DIFF_TICK(sd->K_CHK_NC_MAINFRAME,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_MAINFRAME - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_MAINFRAME >= (battle_config.WOE_K_DELAY_NC_MAINFRAME/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_MAINFRAME >= (battle_config.K_DELAY_NC_MAINFRAME/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_MAINFRAME = sd->K_LOCK_NC_MAINFRAME +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_MAINFRAME = gettick() + battle_config.WOE_K_DELAY_NC_MAINFRAME;
				else
					sd->K_CHK_NC_MAINFRAME = gettick() + battle_config.K_DELAY_NC_MAINFRAME;

				sd->K_LOCK_NC_MAINFRAME = 0;
			}
			break;
		case NC_SHAPESHIFT:
			if(DIFF_TICK(sd->K_CHK_NC_SHAPESHIFT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_SHAPESHIFT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_SHAPESHIFT >= (battle_config.WOE_K_DELAY_NC_SHAPESHIFT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_SHAPESHIFT >= (battle_config.K_DELAY_NC_SHAPESHIFT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_SHAPESHIFT = sd->K_LOCK_NC_SHAPESHIFT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_SHAPESHIFT = gettick() + battle_config.WOE_K_DELAY_NC_SHAPESHIFT;
				else
					sd->K_CHK_NC_SHAPESHIFT = gettick() + battle_config.K_DELAY_NC_SHAPESHIFT;

				sd->K_LOCK_NC_SHAPESHIFT = 0;
			}
			break;
		case NC_INFRAREDSCAN:
			if(DIFF_TICK(sd->K_CHK_NC_INFRAREDSCAN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_INFRAREDSCAN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_INFRAREDSCAN >= (battle_config.WOE_K_DELAY_NC_INFRAREDSCAN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_INFRAREDSCAN >= (battle_config.K_DELAY_NC_INFRAREDSCAN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_INFRAREDSCAN = sd->K_LOCK_NC_INFRAREDSCAN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_INFRAREDSCAN = gettick() + battle_config.WOE_K_DELAY_NC_INFRAREDSCAN;
				else
					sd->K_CHK_NC_INFRAREDSCAN = gettick() + battle_config.K_DELAY_NC_INFRAREDSCAN;

				sd->K_LOCK_NC_INFRAREDSCAN = 0;
			}
			break;
		case NC_ANALYZE:
			if(DIFF_TICK(sd->K_CHK_NC_ANALYZE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_ANALYZE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_ANALYZE >= (battle_config.WOE_K_DELAY_NC_ANALYZE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_ANALYZE >= (battle_config.K_DELAY_NC_ANALYZE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_ANALYZE = sd->K_LOCK_NC_ANALYZE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_ANALYZE = gettick() + battle_config.WOE_K_DELAY_NC_ANALYZE;
				else
					sd->K_CHK_NC_ANALYZE = gettick() + battle_config.K_DELAY_NC_ANALYZE;

				sd->K_LOCK_NC_ANALYZE = 0;
			}
			break;
		case NC_MAGNETICFIELD:
			if(DIFF_TICK(sd->K_CHK_NC_MAGNETICFIELD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_MAGNETICFIELD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_MAGNETICFIELD >= (battle_config.WOE_K_DELAY_NC_MAGNETICFIELD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_MAGNETICFIELD >= (battle_config.K_DELAY_NC_MAGNETICFIELD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_MAGNETICFIELD = sd->K_LOCK_NC_MAGNETICFIELD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_MAGNETICFIELD = gettick() + battle_config.WOE_K_DELAY_NC_MAGNETICFIELD;
				else
					sd->K_CHK_NC_MAGNETICFIELD = gettick() + battle_config.K_DELAY_NC_MAGNETICFIELD;

				sd->K_LOCK_NC_MAGNETICFIELD = 0;
			}
			break;
		case NC_NEUTRALBARRIER:
			if(DIFF_TICK(sd->K_CHK_NC_NEUTRALBARRIER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_NEUTRALBARRIER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_NEUTRALBARRIER >= (battle_config.WOE_K_DELAY_NC_NEUTRALBARRIER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_NEUTRALBARRIER >= (battle_config.K_DELAY_NC_NEUTRALBARRIER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_NEUTRALBARRIER = sd->K_LOCK_NC_NEUTRALBARRIER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_NEUTRALBARRIER = gettick() + battle_config.WOE_K_DELAY_NC_NEUTRALBARRIER;
				else
					sd->K_CHK_NC_NEUTRALBARRIER = gettick() + battle_config.K_DELAY_NC_NEUTRALBARRIER;

				sd->K_LOCK_NC_NEUTRALBARRIER = 0;
			}
			break;
		case NC_STEALTHFIELD:
			if(DIFF_TICK(sd->K_CHK_NC_STEALTHFIELD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_STEALTHFIELD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_STEALTHFIELD >= (battle_config.WOE_K_DELAY_NC_STEALTHFIELD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_STEALTHFIELD >= (battle_config.K_DELAY_NC_STEALTHFIELD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_STEALTHFIELD = sd->K_LOCK_NC_STEALTHFIELD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_STEALTHFIELD = gettick() + battle_config.WOE_K_DELAY_NC_STEALTHFIELD;
				else
					sd->K_CHK_NC_STEALTHFIELD = gettick() + battle_config.K_DELAY_NC_STEALTHFIELD;

				sd->K_LOCK_NC_STEALTHFIELD = 0;
			}
			break;
		case NC_AXEBOOMERANG:
			if(DIFF_TICK(sd->K_CHK_NC_AXEBOOMERANG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_AXEBOOMERANG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_AXEBOOMERANG >= (battle_config.WOE_K_DELAY_NC_AXEBOOMERANG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_AXEBOOMERANG >= (battle_config.K_DELAY_NC_AXEBOOMERANG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_AXEBOOMERANG = sd->K_LOCK_NC_AXEBOOMERANG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_AXEBOOMERANG = gettick() + battle_config.WOE_K_DELAY_NC_AXEBOOMERANG;
				else
					sd->K_CHK_NC_AXEBOOMERANG = gettick() + battle_config.K_DELAY_NC_AXEBOOMERANG;

				sd->K_LOCK_NC_AXEBOOMERANG = 0;
			}
			break;
		case NC_POWERSWING:
			if(DIFF_TICK(sd->K_CHK_NC_POWERSWING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_POWERSWING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_POWERSWING >= (battle_config.WOE_K_DELAY_NC_POWERSWING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_POWERSWING >= (battle_config.K_DELAY_NC_POWERSWING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_POWERSWING = sd->K_LOCK_NC_POWERSWING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_POWERSWING = gettick() + battle_config.WOE_K_DELAY_NC_POWERSWING;
				else
					sd->K_CHK_NC_POWERSWING = gettick() + battle_config.K_DELAY_NC_POWERSWING;

				sd->K_LOCK_NC_POWERSWING = 0;
			}
			break;
		case NC_AXETORNADO:
			if(DIFF_TICK(sd->K_CHK_NC_AXETORNADO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_AXETORNADO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_AXETORNADO >= (battle_config.WOE_K_DELAY_NC_AXETORNADO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_AXETORNADO >= (battle_config.K_DELAY_NC_AXETORNADO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_AXETORNADO = sd->K_LOCK_NC_AXETORNADO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_AXETORNADO = gettick() + battle_config.WOE_K_DELAY_NC_AXETORNADO;
				else
					sd->K_CHK_NC_AXETORNADO = gettick() + battle_config.K_DELAY_NC_AXETORNADO;

				sd->K_LOCK_NC_AXETORNADO = 0;
			}
			break;
		case NC_SILVERSNIPER:
			if(DIFF_TICK(sd->K_CHK_NC_SILVERSNIPER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_SILVERSNIPER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_SILVERSNIPER >= (battle_config.WOE_K_DELAY_NC_SILVERSNIPER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_SILVERSNIPER >= (battle_config.K_DELAY_NC_SILVERSNIPER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_SILVERSNIPER = sd->K_LOCK_NC_SILVERSNIPER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_SILVERSNIPER = gettick() + battle_config.WOE_K_DELAY_NC_SILVERSNIPER;
				else
					sd->K_CHK_NC_SILVERSNIPER = gettick() + battle_config.K_DELAY_NC_SILVERSNIPER;

				sd->K_LOCK_NC_SILVERSNIPER = 0;
			}
			break;
		case NC_MAGICDECOY:
			if(DIFF_TICK(sd->K_CHK_NC_MAGICDECOY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_MAGICDECOY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_MAGICDECOY >= (battle_config.WOE_K_DELAY_NC_MAGICDECOY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_MAGICDECOY >= (battle_config.K_DELAY_NC_MAGICDECOY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_MAGICDECOY = sd->K_LOCK_NC_MAGICDECOY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_MAGICDECOY = gettick() + battle_config.WOE_K_DELAY_NC_MAGICDECOY;
				else
					sd->K_CHK_NC_MAGICDECOY = gettick() + battle_config.K_DELAY_NC_MAGICDECOY;

				sd->K_LOCK_NC_MAGICDECOY = 0;
			}
			break;
		case NC_DISJOINT:
			if(DIFF_TICK(sd->K_CHK_NC_DISJOINT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_DISJOINT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_DISJOINT >= (battle_config.WOE_K_DELAY_NC_DISJOINT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_DISJOINT >= (battle_config.K_DELAY_NC_DISJOINT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_DISJOINT = sd->K_LOCK_NC_DISJOINT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_DISJOINT = gettick() + battle_config.WOE_K_DELAY_NC_DISJOINT;
				else
					sd->K_CHK_NC_DISJOINT = gettick() + battle_config.K_DELAY_NC_DISJOINT;

				sd->K_LOCK_NC_DISJOINT = 0;
			}
			break;
		case SC_FATALMENACE:
			if(DIFF_TICK(sd->K_CHK_SC_FATALMENACE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_FATALMENACE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_FATALMENACE >= (battle_config.WOE_K_DELAY_SC_FATALMENACE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_FATALMENACE >= (battle_config.K_DELAY_SC_FATALMENACE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_FATALMENACE = sd->K_LOCK_SC_FATALMENACE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_FATALMENACE = gettick() + battle_config.WOE_K_DELAY_SC_FATALMENACE;
				else
					sd->K_CHK_SC_FATALMENACE = gettick() + battle_config.K_DELAY_SC_FATALMENACE;

				sd->K_LOCK_SC_FATALMENACE = 0;
			}
			break;
		case SC_TRIANGLESHOT:
			if(DIFF_TICK(sd->K_CHK_SC_TRIANGLESHOT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_TRIANGLESHOT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_TRIANGLESHOT >= (battle_config.WOE_K_DELAY_SC_TRIANGLESHOT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_TRIANGLESHOT >= (battle_config.K_DELAY_SC_TRIANGLESHOT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_TRIANGLESHOT = sd->K_LOCK_SC_TRIANGLESHOT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_TRIANGLESHOT = gettick() + battle_config.WOE_K_DELAY_SC_TRIANGLESHOT;
				else
					sd->K_CHK_SC_TRIANGLESHOT = gettick() + battle_config.K_DELAY_SC_TRIANGLESHOT;

				sd->K_LOCK_SC_TRIANGLESHOT = 0;
			}
			break;
		case SC_INVISIBILITY:
			if(DIFF_TICK(sd->K_CHK_SC_INVISIBILITY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_INVISIBILITY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_INVISIBILITY >= (battle_config.WOE_K_DELAY_SC_INVISIBILITY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_INVISIBILITY >= (battle_config.K_DELAY_SC_INVISIBILITY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_INVISIBILITY = sd->K_LOCK_SC_INVISIBILITY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_INVISIBILITY = gettick() + battle_config.WOE_K_DELAY_SC_INVISIBILITY;
				else
					sd->K_CHK_SC_INVISIBILITY = gettick() + battle_config.K_DELAY_SC_INVISIBILITY;

				sd->K_LOCK_SC_INVISIBILITY = 0;
			}
			break;
		case SC_ENERVATION:
			if(DIFF_TICK(sd->K_CHK_SC_ENERVATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_ENERVATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_ENERVATION >= (battle_config.WOE_K_DELAY_SC_ENERVATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_ENERVATION >= (battle_config.K_DELAY_SC_ENERVATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_ENERVATION = sd->K_LOCK_SC_ENERVATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_ENERVATION = gettick() + battle_config.WOE_K_DELAY_SC_ENERVATION;
				else
					sd->K_CHK_SC_ENERVATION = gettick() + battle_config.K_DELAY_SC_ENERVATION;

				sd->K_LOCK_SC_ENERVATION = 0;
			}
			break;
		case SC_GROOMY:
			if(DIFF_TICK(sd->K_CHK_SC_GROOMY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_GROOMY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_GROOMY >= (battle_config.WOE_K_DELAY_SC_GROOMY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_GROOMY >= (battle_config.K_DELAY_SC_GROOMY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_GROOMY = sd->K_LOCK_SC_GROOMY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_GROOMY = gettick() + battle_config.WOE_K_DELAY_SC_GROOMY;
				else
					sd->K_CHK_SC_GROOMY = gettick() + battle_config.K_DELAY_SC_GROOMY;

				sd->K_LOCK_SC_GROOMY = 0;
			}
			break;
		case SC_IGNORANCE:
			if(DIFF_TICK(sd->K_CHK_SC_IGNORANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_IGNORANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_IGNORANCE >= (battle_config.WOE_K_DELAY_SC_IGNORANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_IGNORANCE >= (battle_config.K_DELAY_SC_IGNORANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_IGNORANCE = sd->K_LOCK_SC_IGNORANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_IGNORANCE = gettick() + battle_config.WOE_K_DELAY_SC_IGNORANCE;
				else
					sd->K_CHK_SC_IGNORANCE = gettick() + battle_config.K_DELAY_SC_IGNORANCE;

				sd->K_LOCK_SC_IGNORANCE = 0;
			}
			break;
		case SC_LAZINESS:
			if(DIFF_TICK(sd->K_CHK_SC_LAZINESS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_LAZINESS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_LAZINESS >= (battle_config.WOE_K_DELAY_SC_LAZINESS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_LAZINESS >= (battle_config.K_DELAY_SC_LAZINESS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_LAZINESS = sd->K_LOCK_SC_LAZINESS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_LAZINESS = gettick() + battle_config.WOE_K_DELAY_SC_LAZINESS;
				else
					sd->K_CHK_SC_LAZINESS = gettick() + battle_config.K_DELAY_SC_LAZINESS;

				sd->K_LOCK_SC_LAZINESS = 0;
			}
			break;
		case SC_UNLUCKY:
			if(DIFF_TICK(sd->K_CHK_SC_UNLUCKY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_UNLUCKY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_UNLUCKY >= (battle_config.WOE_K_DELAY_SC_UNLUCKY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_UNLUCKY >= (battle_config.K_DELAY_SC_UNLUCKY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_UNLUCKY = sd->K_LOCK_SC_UNLUCKY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_UNLUCKY = gettick() + battle_config.WOE_K_DELAY_SC_UNLUCKY;
				else
					sd->K_CHK_SC_UNLUCKY = gettick() + battle_config.K_DELAY_SC_UNLUCKY;

				sd->K_LOCK_SC_UNLUCKY = 0;
			}
			break;
		case SC_WEAKNESS:
			if(DIFF_TICK(sd->K_CHK_SC_WEAKNESS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_WEAKNESS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_WEAKNESS >= (battle_config.WOE_K_DELAY_SC_WEAKNESS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_WEAKNESS >= (battle_config.K_DELAY_SC_WEAKNESS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_WEAKNESS = sd->K_LOCK_SC_WEAKNESS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_WEAKNESS = gettick() + battle_config.WOE_K_DELAY_SC_WEAKNESS;
				else
					sd->K_CHK_SC_WEAKNESS = gettick() + battle_config.K_DELAY_SC_WEAKNESS;

				sd->K_LOCK_SC_WEAKNESS = 0;
			}
			break;
		case SC_STRIPACCESSARY:
			if(DIFF_TICK(sd->K_CHK_SC_STRIPACCESSARY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_STRIPACCESSARY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_STRIPACCESSARY >= (battle_config.WOE_K_DELAY_SC_STRIPACCESSARY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_STRIPACCESSARY >= (battle_config.K_DELAY_SC_STRIPACCESSARY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_STRIPACCESSARY = sd->K_LOCK_SC_STRIPACCESSARY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_STRIPACCESSARY = gettick() + battle_config.WOE_K_DELAY_SC_STRIPACCESSARY;
				else
					sd->K_CHK_SC_STRIPACCESSARY = gettick() + battle_config.K_DELAY_SC_STRIPACCESSARY;

				sd->K_LOCK_SC_STRIPACCESSARY = 0;
			}
			break;
		case SC_MANHOLE:
			if(DIFF_TICK(sd->K_CHK_SC_MANHOLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_MANHOLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_MANHOLE >= (battle_config.WOE_K_DELAY_SC_MANHOLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_MANHOLE >= (battle_config.K_DELAY_SC_MANHOLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_MANHOLE = sd->K_LOCK_SC_MANHOLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_MANHOLE = gettick() + battle_config.WOE_K_DELAY_SC_MANHOLE;
				else
					sd->K_CHK_SC_MANHOLE = gettick() + battle_config.K_DELAY_SC_MANHOLE;

				sd->K_LOCK_SC_MANHOLE = 0;
			}
			break;
		case SC_DIMENSIONDOOR:
			if(DIFF_TICK(sd->K_CHK_SC_DIMENSIONDOOR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_DIMENSIONDOOR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_DIMENSIONDOOR >= (battle_config.WOE_K_DELAY_SC_DIMENSIONDOOR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_DIMENSIONDOOR >= (battle_config.K_DELAY_SC_DIMENSIONDOOR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_DIMENSIONDOOR = sd->K_LOCK_SC_DIMENSIONDOOR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_DIMENSIONDOOR = gettick() + battle_config.WOE_K_DELAY_SC_DIMENSIONDOOR;
				else
					sd->K_CHK_SC_DIMENSIONDOOR = gettick() + battle_config.K_DELAY_SC_DIMENSIONDOOR;

				sd->K_LOCK_SC_DIMENSIONDOOR = 0;
			}
			break;
		case SC_CHAOSPANIC:
			if(DIFF_TICK(sd->K_CHK_SC_CHAOSPANIC,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_CHAOSPANIC - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_CHAOSPANIC >= (battle_config.WOE_K_DELAY_SC_CHAOSPANIC/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_CHAOSPANIC >= (battle_config.K_DELAY_SC_CHAOSPANIC/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_CHAOSPANIC = sd->K_LOCK_SC_CHAOSPANIC +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_CHAOSPANIC = gettick() + battle_config.WOE_K_DELAY_SC_CHAOSPANIC;
				else
					sd->K_CHK_SC_CHAOSPANIC = gettick() + battle_config.K_DELAY_SC_CHAOSPANIC;

				sd->K_LOCK_SC_CHAOSPANIC = 0;
			}
			break;
		case SC_MAELSTROM:
			if(DIFF_TICK(sd->K_CHK_SC_MAELSTROM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_MAELSTROM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_MAELSTROM >= (battle_config.WOE_K_DELAY_SC_MAELSTROM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_MAELSTROM >= (battle_config.K_DELAY_SC_MAELSTROM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_MAELSTROM = sd->K_LOCK_SC_MAELSTROM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_MAELSTROM = gettick() + battle_config.WOE_K_DELAY_SC_MAELSTROM;
				else
					sd->K_CHK_SC_MAELSTROM = gettick() + battle_config.K_DELAY_SC_MAELSTROM;

				sd->K_LOCK_SC_MAELSTROM = 0;
			}
			break;
		case SC_BLOODYLUST:
			if(DIFF_TICK(sd->K_CHK_SC_BLOODYLUST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_BLOODYLUST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_BLOODYLUST >= (battle_config.WOE_K_DELAY_SC_BLOODYLUST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_BLOODYLUST >= (battle_config.K_DELAY_SC_BLOODYLUST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_BLOODYLUST = sd->K_LOCK_SC_BLOODYLUST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_BLOODYLUST = gettick() + battle_config.WOE_K_DELAY_SC_BLOODYLUST;
				else
					sd->K_CHK_SC_BLOODYLUST = gettick() + battle_config.K_DELAY_SC_BLOODYLUST;

				sd->K_LOCK_SC_BLOODYLUST = 0;
			}
			break;
		case SC_FEINTBOMB:
			if(DIFF_TICK(sd->K_CHK_SC_FEINTBOMB,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_FEINTBOMB - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_FEINTBOMB >= (battle_config.WOE_K_DELAY_SC_FEINTBOMB/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_FEINTBOMB >= (battle_config.K_DELAY_SC_FEINTBOMB/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_FEINTBOMB = sd->K_LOCK_SC_FEINTBOMB +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_FEINTBOMB = gettick() + battle_config.WOE_K_DELAY_SC_FEINTBOMB;
				else
					sd->K_CHK_SC_FEINTBOMB = gettick() + battle_config.K_DELAY_SC_FEINTBOMB;

				sd->K_LOCK_SC_FEINTBOMB = 0;
			}
			break;
		case LG_CANNONSPEAR:
			if(DIFF_TICK(sd->K_CHK_LG_CANNONSPEAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_CANNONSPEAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_CANNONSPEAR >= (battle_config.WOE_K_DELAY_LG_CANNONSPEAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_CANNONSPEAR >= (battle_config.K_DELAY_LG_CANNONSPEAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_CANNONSPEAR = sd->K_LOCK_LG_CANNONSPEAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_CANNONSPEAR = gettick() + battle_config.WOE_K_DELAY_LG_CANNONSPEAR;
				else
					sd->K_CHK_LG_CANNONSPEAR = gettick() + battle_config.K_DELAY_LG_CANNONSPEAR;

				sd->K_LOCK_LG_CANNONSPEAR = 0;
			}
			break;
		case LG_BANISHINGPOINT:
			if(DIFF_TICK(sd->K_CHK_LG_BANISHINGPOINT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_BANISHINGPOINT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_BANISHINGPOINT >= (battle_config.WOE_K_DELAY_LG_BANISHINGPOINT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_BANISHINGPOINT >= (battle_config.K_DELAY_LG_BANISHINGPOINT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_BANISHINGPOINT = sd->K_LOCK_LG_BANISHINGPOINT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_BANISHINGPOINT = gettick() + battle_config.WOE_K_DELAY_LG_BANISHINGPOINT;
				else
					sd->K_CHK_LG_BANISHINGPOINT = gettick() + battle_config.K_DELAY_LG_BANISHINGPOINT;

				sd->K_LOCK_LG_BANISHINGPOINT = 0;
			}
			break;
		case LG_TRAMPLE:
			if(DIFF_TICK(sd->K_CHK_LG_TRAMPLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_TRAMPLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_TRAMPLE >= (battle_config.WOE_K_DELAY_LG_TRAMPLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_TRAMPLE >= (battle_config.K_DELAY_LG_TRAMPLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_TRAMPLE = sd->K_LOCK_LG_TRAMPLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_TRAMPLE = gettick() + battle_config.WOE_K_DELAY_LG_TRAMPLE;
				else
					sd->K_CHK_LG_TRAMPLE = gettick() + battle_config.K_DELAY_LG_TRAMPLE;

				sd->K_LOCK_LG_TRAMPLE = 0;
			}
			break;
		case LG_PINPOINTATTACK:
			if(DIFF_TICK(sd->K_CHK_LG_PINPOINTATTACK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_PINPOINTATTACK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_PINPOINTATTACK >= (battle_config.WOE_K_DELAY_LG_PINPOINTATTACK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_PINPOINTATTACK >= (battle_config.K_DELAY_LG_PINPOINTATTACK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_PINPOINTATTACK = sd->K_LOCK_LG_PINPOINTATTACK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_PINPOINTATTACK = gettick() + battle_config.WOE_K_DELAY_LG_PINPOINTATTACK;
				else
					sd->K_CHK_LG_PINPOINTATTACK = gettick() + battle_config.K_DELAY_LG_PINPOINTATTACK;

				sd->K_LOCK_LG_PINPOINTATTACK = 0;
			}
			break;
		case LG_RAGEBURST:
			if(DIFF_TICK(sd->K_CHK_LG_RAGEBURST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_RAGEBURST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_RAGEBURST >= (battle_config.WOE_K_DELAY_LG_RAGEBURST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_RAGEBURST >= (battle_config.K_DELAY_LG_RAGEBURST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_RAGEBURST = sd->K_LOCK_LG_RAGEBURST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_RAGEBURST = gettick() + battle_config.WOE_K_DELAY_LG_RAGEBURST;
				else
					sd->K_CHK_LG_RAGEBURST = gettick() + battle_config.K_DELAY_LG_RAGEBURST;

				sd->K_LOCK_LG_RAGEBURST = 0;
			}
			break;
		case LG_EXEEDBREAK:
			if(DIFF_TICK(sd->K_CHK_LG_EXEEDBREAK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_EXEEDBREAK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_EXEEDBREAK >= (battle_config.WOE_K_DELAY_LG_EXEEDBREAK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_EXEEDBREAK >= (battle_config.K_DELAY_LG_EXEEDBREAK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_EXEEDBREAK = sd->K_LOCK_LG_EXEEDBREAK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_EXEEDBREAK = gettick() + battle_config.WOE_K_DELAY_LG_EXEEDBREAK;
				else
					sd->K_CHK_LG_EXEEDBREAK = gettick() + battle_config.K_DELAY_LG_EXEEDBREAK;

				sd->K_LOCK_LG_EXEEDBREAK = 0;
			}
			break;
		case LG_OVERBRAND:
			if(DIFF_TICK(sd->K_CHK_LG_OVERBRAND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_OVERBRAND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_OVERBRAND >= (battle_config.WOE_K_DELAY_LG_OVERBRAND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_OVERBRAND >= (battle_config.K_DELAY_LG_OVERBRAND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_OVERBRAND = sd->K_LOCK_LG_OVERBRAND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_OVERBRAND = gettick() + battle_config.WOE_K_DELAY_LG_OVERBRAND;
				else
					sd->K_CHK_LG_OVERBRAND = gettick() + battle_config.K_DELAY_LG_OVERBRAND;

				sd->K_LOCK_LG_OVERBRAND = 0;
			}
			break;
		case LG_BANDING:
			if(DIFF_TICK(sd->K_CHK_LG_BANDING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_BANDING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_BANDING >= (battle_config.WOE_K_DELAY_LG_BANDING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_BANDING >= (battle_config.K_DELAY_LG_BANDING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_BANDING = sd->K_LOCK_LG_BANDING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_BANDING = gettick() + battle_config.WOE_K_DELAY_LG_BANDING;
				else
					sd->K_CHK_LG_BANDING = gettick() + battle_config.K_DELAY_LG_BANDING;

				sd->K_LOCK_LG_BANDING = 0;
			}
			break;
		case LG_MOONSLASHER:
			if(DIFF_TICK(sd->K_CHK_LG_MOONSLASHER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_MOONSLASHER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_MOONSLASHER >= (battle_config.WOE_K_DELAY_LG_MOONSLASHER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_MOONSLASHER >= (battle_config.K_DELAY_LG_MOONSLASHER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_MOONSLASHER = sd->K_LOCK_LG_MOONSLASHER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_MOONSLASHER = gettick() + battle_config.WOE_K_DELAY_LG_MOONSLASHER;
				else
					sd->K_CHK_LG_MOONSLASHER = gettick() + battle_config.K_DELAY_LG_MOONSLASHER;

				sd->K_LOCK_LG_MOONSLASHER = 0;
			}
			break;
		case LG_RAYOFGENESIS:
			if(DIFF_TICK(sd->K_CHK_LG_RAYOFGENESIS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_RAYOFGENESIS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_RAYOFGENESIS >= (battle_config.WOE_K_DELAY_LG_RAYOFGENESIS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_RAYOFGENESIS >= (battle_config.K_DELAY_LG_RAYOFGENESIS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_RAYOFGENESIS = sd->K_LOCK_LG_RAYOFGENESIS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_RAYOFGENESIS = gettick() + battle_config.WOE_K_DELAY_LG_RAYOFGENESIS;
				else
					sd->K_CHK_LG_RAYOFGENESIS = gettick() + battle_config.K_DELAY_LG_RAYOFGENESIS;

				sd->K_LOCK_LG_RAYOFGENESIS = 0;
			}
			break;
		case LG_PIETY:
			if(DIFF_TICK(sd->K_CHK_LG_PIETY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_PIETY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_PIETY >= (battle_config.WOE_K_DELAY_LG_PIETY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_PIETY >= (battle_config.K_DELAY_LG_PIETY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_PIETY = sd->K_LOCK_LG_PIETY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_PIETY = gettick() + battle_config.WOE_K_DELAY_LG_PIETY;
				else
					sd->K_CHK_LG_PIETY = gettick() + battle_config.K_DELAY_LG_PIETY;

				sd->K_LOCK_LG_PIETY = 0;
			}
			break;
		case LG_EARTHDRIVE:
			if(DIFF_TICK(sd->K_CHK_LG_EARTHDRIVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_EARTHDRIVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_EARTHDRIVE >= (battle_config.WOE_K_DELAY_LG_EARTHDRIVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_EARTHDRIVE >= (battle_config.K_DELAY_LG_EARTHDRIVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_EARTHDRIVE = sd->K_LOCK_LG_EARTHDRIVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_EARTHDRIVE = gettick() + battle_config.WOE_K_DELAY_LG_EARTHDRIVE;
				else
					sd->K_CHK_LG_EARTHDRIVE = gettick() + battle_config.K_DELAY_LG_EARTHDRIVE;

				sd->K_LOCK_LG_EARTHDRIVE = 0;
			}
			break;
		case LG_HESPERUSLIT:
			if(DIFF_TICK(sd->K_CHK_LG_HESPERUSLIT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_HESPERUSLIT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_HESPERUSLIT >= (battle_config.WOE_K_DELAY_LG_HESPERUSLIT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_HESPERUSLIT >= (battle_config.K_DELAY_LG_HESPERUSLIT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_HESPERUSLIT = sd->K_LOCK_LG_HESPERUSLIT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_HESPERUSLIT = gettick() + battle_config.WOE_K_DELAY_LG_HESPERUSLIT;
				else
					sd->K_CHK_LG_HESPERUSLIT = gettick() + battle_config.K_DELAY_LG_HESPERUSLIT;

				sd->K_LOCK_LG_HESPERUSLIT = 0;
			}
			break;
		case SR_DRAGONCOMBO:
			if(DIFF_TICK(sd->K_CHK_SR_DRAGONCOMBO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_DRAGONCOMBO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_DRAGONCOMBO >= (battle_config.WOE_K_DELAY_SR_DRAGONCOMBO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_DRAGONCOMBO >= (battle_config.K_DELAY_SR_DRAGONCOMBO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_DRAGONCOMBO = sd->K_LOCK_SR_DRAGONCOMBO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_DRAGONCOMBO = gettick() + battle_config.WOE_K_DELAY_SR_DRAGONCOMBO;
				else
					sd->K_CHK_SR_DRAGONCOMBO = gettick() + battle_config.K_DELAY_SR_DRAGONCOMBO;

				sd->K_LOCK_SR_DRAGONCOMBO = 0;
			}
			break;
		case SR_SKYNETBLOW:
			if(DIFF_TICK(sd->K_CHK_SR_SKYNETBLOW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_SKYNETBLOW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_SKYNETBLOW >= (battle_config.WOE_K_DELAY_SR_SKYNETBLOW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_SKYNETBLOW >= (battle_config.K_DELAY_SR_SKYNETBLOW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_SKYNETBLOW = sd->K_LOCK_SR_SKYNETBLOW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_SKYNETBLOW = gettick() + battle_config.WOE_K_DELAY_SR_SKYNETBLOW;
				else
					sd->K_CHK_SR_SKYNETBLOW = gettick() + battle_config.K_DELAY_SR_SKYNETBLOW;

				sd->K_LOCK_SR_SKYNETBLOW = 0;
			}
			break;
		case SR_EARTHSHAKER:
			if(DIFF_TICK(sd->K_CHK_SR_EARTHSHAKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_EARTHSHAKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_EARTHSHAKER >= (battle_config.WOE_K_DELAY_SR_EARTHSHAKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_EARTHSHAKER >= (battle_config.K_DELAY_SR_EARTHSHAKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_EARTHSHAKER = sd->K_LOCK_SR_EARTHSHAKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_EARTHSHAKER = gettick() + battle_config.WOE_K_DELAY_SR_EARTHSHAKER;
				else
					sd->K_CHK_SR_EARTHSHAKER = gettick() + battle_config.K_DELAY_SR_EARTHSHAKER;

				sd->K_LOCK_SR_EARTHSHAKER = 0;
			}
			break;
		case SR_FALLENEMPIRE:
			if(DIFF_TICK(sd->K_CHK_SR_FALLENEMPIRE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_FALLENEMPIRE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_FALLENEMPIRE >= (battle_config.WOE_K_DELAY_SR_FALLENEMPIRE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_FALLENEMPIRE >= (battle_config.K_DELAY_SR_FALLENEMPIRE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_FALLENEMPIRE = sd->K_LOCK_SR_FALLENEMPIRE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_FALLENEMPIRE = gettick() + battle_config.WOE_K_DELAY_SR_FALLENEMPIRE;
				else
					sd->K_CHK_SR_FALLENEMPIRE = gettick() + battle_config.K_DELAY_SR_FALLENEMPIRE;

				sd->K_LOCK_SR_FALLENEMPIRE = 0;
			}
			break;
		case SR_TIGERCANNON:
			if(DIFF_TICK(sd->K_CHK_SR_TIGERCANNON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_TIGERCANNON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_TIGERCANNON >= (battle_config.WOE_K_DELAY_SR_TIGERCANNON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_TIGERCANNON >= (battle_config.K_DELAY_SR_TIGERCANNON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_TIGERCANNON = sd->K_LOCK_SR_TIGERCANNON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_TIGERCANNON = gettick() + battle_config.WOE_K_DELAY_SR_TIGERCANNON;
				else
					sd->K_CHK_SR_TIGERCANNON = gettick() + battle_config.K_DELAY_SR_TIGERCANNON;

				sd->K_LOCK_SR_TIGERCANNON = 0;
			}
			break;
		case SR_HELLGATE:
			if(DIFF_TICK(sd->K_CHK_SR_HELLGATE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_HELLGATE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_HELLGATE >= (battle_config.WOE_K_DELAY_SR_HELLGATE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_HELLGATE >= (battle_config.K_DELAY_SR_HELLGATE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_HELLGATE = sd->K_LOCK_SR_HELLGATE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_HELLGATE = gettick() + battle_config.WOE_K_DELAY_SR_HELLGATE;
				else
					sd->K_CHK_SR_HELLGATE = gettick() + battle_config.K_DELAY_SR_HELLGATE;

				sd->K_LOCK_SR_HELLGATE = 0;
			}
			break;
		case SR_RAMPAGEBLASTER:
			if(DIFF_TICK(sd->K_CHK_SR_RAMPAGEBLASTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_RAMPAGEBLASTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_RAMPAGEBLASTER >= (battle_config.WOE_K_DELAY_SR_RAMPAGEBLASTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_RAMPAGEBLASTER >= (battle_config.K_DELAY_SR_RAMPAGEBLASTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_RAMPAGEBLASTER = sd->K_LOCK_SR_RAMPAGEBLASTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_RAMPAGEBLASTER = gettick() + battle_config.WOE_K_DELAY_SR_RAMPAGEBLASTER;
				else
					sd->K_CHK_SR_RAMPAGEBLASTER = gettick() + battle_config.K_DELAY_SR_RAMPAGEBLASTER;

				sd->K_LOCK_SR_RAMPAGEBLASTER = 0;
			}
			break;
		case SR_CRESCENTELBOW:
			if(DIFF_TICK(sd->K_CHK_SR_CRESCENTELBOW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_CRESCENTELBOW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_CRESCENTELBOW >= (battle_config.WOE_K_DELAY_SR_CRESCENTELBOW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_CRESCENTELBOW >= (battle_config.K_DELAY_SR_CRESCENTELBOW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_CRESCENTELBOW = sd->K_LOCK_SR_CRESCENTELBOW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_CRESCENTELBOW = gettick() + battle_config.WOE_K_DELAY_SR_CRESCENTELBOW;
				else
					sd->K_CHK_SR_CRESCENTELBOW = gettick() + battle_config.K_DELAY_SR_CRESCENTELBOW;

				sd->K_LOCK_SR_CRESCENTELBOW = 0;
			}
			break;
		case SR_CURSEDCIRCLE:
			if(DIFF_TICK(sd->K_CHK_SR_CURSEDCIRCLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_CURSEDCIRCLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_CURSEDCIRCLE >= (battle_config.WOE_K_DELAY_SR_CURSEDCIRCLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_CURSEDCIRCLE >= (battle_config.K_DELAY_SR_CURSEDCIRCLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_CURSEDCIRCLE = sd->K_LOCK_SR_CURSEDCIRCLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_CURSEDCIRCLE = gettick() + battle_config.WOE_K_DELAY_SR_CURSEDCIRCLE;
				else
					sd->K_CHK_SR_CURSEDCIRCLE = gettick() + battle_config.K_DELAY_SR_CURSEDCIRCLE;

				sd->K_LOCK_SR_CURSEDCIRCLE = 0;
			}
			break;
		case SR_LIGHTNINGWALK:
			if(DIFF_TICK(sd->K_CHK_SR_LIGHTNINGWALK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_LIGHTNINGWALK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_LIGHTNINGWALK >= (battle_config.WOE_K_DELAY_SR_LIGHTNINGWALK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_LIGHTNINGWALK >= (battle_config.K_DELAY_SR_LIGHTNINGWALK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_LIGHTNINGWALK = sd->K_LOCK_SR_LIGHTNINGWALK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_LIGHTNINGWALK = gettick() + battle_config.WOE_K_DELAY_SR_LIGHTNINGWALK;
				else
					sd->K_CHK_SR_LIGHTNINGWALK = gettick() + battle_config.K_DELAY_SR_LIGHTNINGWALK;

				sd->K_LOCK_SR_LIGHTNINGWALK = 0;
			}
			break;
		case SR_KNUCKLEARROW:
			if(DIFF_TICK(sd->K_CHK_SR_KNUCKLEARROW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_KNUCKLEARROW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_KNUCKLEARROW >= (battle_config.WOE_K_DELAY_SR_KNUCKLEARROW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_KNUCKLEARROW >= (battle_config.K_DELAY_SR_KNUCKLEARROW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_KNUCKLEARROW = sd->K_LOCK_SR_KNUCKLEARROW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_KNUCKLEARROW = gettick() + battle_config.WOE_K_DELAY_SR_KNUCKLEARROW;
				else
					sd->K_CHK_SR_KNUCKLEARROW = gettick() + battle_config.K_DELAY_SR_KNUCKLEARROW;

				sd->K_LOCK_SR_KNUCKLEARROW = 0;
			}
			break;
		case SR_WINDMILL:
			if(DIFF_TICK(sd->K_CHK_SR_WINDMILL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_WINDMILL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_WINDMILL >= (battle_config.WOE_K_DELAY_SR_WINDMILL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_WINDMILL >= (battle_config.K_DELAY_SR_WINDMILL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_WINDMILL = sd->K_LOCK_SR_WINDMILL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_WINDMILL = gettick() + battle_config.WOE_K_DELAY_SR_WINDMILL;
				else
					sd->K_CHK_SR_WINDMILL = gettick() + battle_config.K_DELAY_SR_WINDMILL;

				sd->K_LOCK_SR_WINDMILL = 0;
			}
			break;
		case SR_RAISINGDRAGON:
			if(DIFF_TICK(sd->K_CHK_SR_RAISINGDRAGON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_RAISINGDRAGON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_RAISINGDRAGON >= (battle_config.WOE_K_DELAY_SR_RAISINGDRAGON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_RAISINGDRAGON >= (battle_config.K_DELAY_SR_RAISINGDRAGON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_RAISINGDRAGON = sd->K_LOCK_SR_RAISINGDRAGON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_RAISINGDRAGON = gettick() + battle_config.WOE_K_DELAY_SR_RAISINGDRAGON;
				else
					sd->K_CHK_SR_RAISINGDRAGON = gettick() + battle_config.K_DELAY_SR_RAISINGDRAGON;

				sd->K_LOCK_SR_RAISINGDRAGON = 0;
			}
			break;
		case SR_GENTLETOUCH:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH >= (battle_config.K_DELAY_SR_GENTLETOUCH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH = sd->K_LOCK_SR_GENTLETOUCH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH;
				else
					sd->K_CHK_SR_GENTLETOUCH = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH;

				sd->K_LOCK_SR_GENTLETOUCH = 0;
			}
			break;
		case SR_ASSIMILATEPOWER:
			if(DIFF_TICK(sd->K_CHK_SR_ASSIMILATEPOWER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_ASSIMILATEPOWER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_ASSIMILATEPOWER >= (battle_config.WOE_K_DELAY_SR_ASSIMILATEPOWER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_ASSIMILATEPOWER >= (battle_config.K_DELAY_SR_ASSIMILATEPOWER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_ASSIMILATEPOWER = sd->K_LOCK_SR_ASSIMILATEPOWER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_ASSIMILATEPOWER = gettick() + battle_config.WOE_K_DELAY_SR_ASSIMILATEPOWER;
				else
					sd->K_CHK_SR_ASSIMILATEPOWER = gettick() + battle_config.K_DELAY_SR_ASSIMILATEPOWER;

				sd->K_LOCK_SR_ASSIMILATEPOWER = 0;
			}
			break;
		case SR_POWERVELOCITY:
			if(DIFF_TICK(sd->K_CHK_SR_POWERVELOCITY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_POWERVELOCITY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_POWERVELOCITY >= (battle_config.WOE_K_DELAY_SR_POWERVELOCITY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_POWERVELOCITY >= (battle_config.K_DELAY_SR_POWERVELOCITY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_POWERVELOCITY = sd->K_LOCK_SR_POWERVELOCITY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_POWERVELOCITY = gettick() + battle_config.WOE_K_DELAY_SR_POWERVELOCITY;
				else
					sd->K_CHK_SR_POWERVELOCITY = gettick() + battle_config.K_DELAY_SR_POWERVELOCITY;

				sd->K_LOCK_SR_POWERVELOCITY = 0;
			}
			break;
		case SR_CRESCENTELBOW_AUTOSPELL:
			if(DIFF_TICK(sd->K_CHK_SR_CRESCENTELBOW_AUTOSPELL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_CRESCENTELBOW_AUTOSPELL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_CRESCENTELBOW_AUTOSPELL >= (battle_config.WOE_K_DELAY_SR_CRESCENTELBOW_AUTOSPELL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_CRESCENTELBOW_AUTOSPELL >= (battle_config.K_DELAY_SR_CRESCENTELBOW_AUTOSPELL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_CRESCENTELBOW_AUTOSPELL = sd->K_LOCK_SR_CRESCENTELBOW_AUTOSPELL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_CRESCENTELBOW_AUTOSPELL = gettick() + battle_config.WOE_K_DELAY_SR_CRESCENTELBOW_AUTOSPELL;
				else
					sd->K_CHK_SR_CRESCENTELBOW_AUTOSPELL = gettick() + battle_config.K_DELAY_SR_CRESCENTELBOW_AUTOSPELL;

				sd->K_LOCK_SR_CRESCENTELBOW_AUTOSPELL = 0;
			}
			break;
		case SR_GATEOFHELL:
			if(DIFF_TICK(sd->K_CHK_SR_GATEOFHELL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GATEOFHELL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GATEOFHELL >= (battle_config.WOE_K_DELAY_SR_GATEOFHELL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GATEOFHELL >= (battle_config.K_DELAY_SR_GATEOFHELL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GATEOFHELL = sd->K_LOCK_SR_GATEOFHELL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GATEOFHELL = gettick() + battle_config.WOE_K_DELAY_SR_GATEOFHELL;
				else
					sd->K_CHK_SR_GATEOFHELL = gettick() + battle_config.K_DELAY_SR_GATEOFHELL;

				sd->K_LOCK_SR_GATEOFHELL = 0;
			}
			break;
		case SR_GENTLETOUCH_QUIET:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH_QUIET,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH_QUIET - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH_QUIET >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH_QUIET/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH_QUIET >= (battle_config.K_DELAY_SR_GENTLETOUCH_QUIET/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH_QUIET = sd->K_LOCK_SR_GENTLETOUCH_QUIET +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH_QUIET = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH_QUIET;
				else
					sd->K_CHK_SR_GENTLETOUCH_QUIET = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH_QUIET;

				sd->K_LOCK_SR_GENTLETOUCH_QUIET = 0;
			}
			break;
		case SR_GENTLETOUCH_CURE:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH_CURE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH_CURE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH_CURE >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH_CURE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH_CURE >= (battle_config.K_DELAY_SR_GENTLETOUCH_CURE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH_CURE = sd->K_LOCK_SR_GENTLETOUCH_CURE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH_CURE = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH_CURE;
				else
					sd->K_CHK_SR_GENTLETOUCH_CURE = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH_CURE;

				sd->K_LOCK_SR_GENTLETOUCH_CURE = 0;
			}
			break;
		case SR_GENTLETOUCH_ENERGYGAIN:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH_ENERGYGAIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH_ENERGYGAIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH_ENERGYGAIN >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH_ENERGYGAIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH_ENERGYGAIN >= (battle_config.K_DELAY_SR_GENTLETOUCH_ENERGYGAIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH_ENERGYGAIN = sd->K_LOCK_SR_GENTLETOUCH_ENERGYGAIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH_ENERGYGAIN = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH_ENERGYGAIN;
				else
					sd->K_CHK_SR_GENTLETOUCH_ENERGYGAIN = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH_ENERGYGAIN;

				sd->K_LOCK_SR_GENTLETOUCH_ENERGYGAIN = 0;
			}
			break;
		case SR_GENTLETOUCH_CHANGE:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH_CHANGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH_CHANGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH_CHANGE >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH_CHANGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH_CHANGE >= (battle_config.K_DELAY_SR_GENTLETOUCH_CHANGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH_CHANGE = sd->K_LOCK_SR_GENTLETOUCH_CHANGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH_CHANGE = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH_CHANGE;
				else
					sd->K_CHK_SR_GENTLETOUCH_CHANGE = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH_CHANGE;

				sd->K_LOCK_SR_GENTLETOUCH_CHANGE = 0;
			}
			break;
		case SR_GENTLETOUCH_REVITALIZE:
			if(DIFF_TICK(sd->K_CHK_SR_GENTLETOUCH_REVITALIZE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_GENTLETOUCH_REVITALIZE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_GENTLETOUCH_REVITALIZE >= (battle_config.WOE_K_DELAY_SR_GENTLETOUCH_REVITALIZE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_GENTLETOUCH_REVITALIZE >= (battle_config.K_DELAY_SR_GENTLETOUCH_REVITALIZE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_GENTLETOUCH_REVITALIZE = sd->K_LOCK_SR_GENTLETOUCH_REVITALIZE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_GENTLETOUCH_REVITALIZE = gettick() + battle_config.WOE_K_DELAY_SR_GENTLETOUCH_REVITALIZE;
				else
					sd->K_CHK_SR_GENTLETOUCH_REVITALIZE = gettick() + battle_config.K_DELAY_SR_GENTLETOUCH_REVITALIZE;

				sd->K_LOCK_SR_GENTLETOUCH_REVITALIZE = 0;
			}
			break;
		case WA_SWING_DANCE:
			if(DIFF_TICK(sd->K_CHK_WA_SWING_DANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WA_SWING_DANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WA_SWING_DANCE >= (battle_config.WOE_K_DELAY_WA_SWING_DANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WA_SWING_DANCE >= (battle_config.K_DELAY_WA_SWING_DANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WA_SWING_DANCE = sd->K_LOCK_WA_SWING_DANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WA_SWING_DANCE = gettick() + battle_config.WOE_K_DELAY_WA_SWING_DANCE;
				else
					sd->K_CHK_WA_SWING_DANCE = gettick() + battle_config.K_DELAY_WA_SWING_DANCE;

				sd->K_LOCK_WA_SWING_DANCE = 0;
			}
			break;
		case WA_SYMPHONY_OF_LOVER:
			if(DIFF_TICK(sd->K_CHK_WA_SYMPHONY_OF_LOVER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WA_SYMPHONY_OF_LOVER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WA_SYMPHONY_OF_LOVER >= (battle_config.WOE_K_DELAY_WA_SYMPHONY_OF_LOVER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WA_SYMPHONY_OF_LOVER >= (battle_config.K_DELAY_WA_SYMPHONY_OF_LOVER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WA_SYMPHONY_OF_LOVER = sd->K_LOCK_WA_SYMPHONY_OF_LOVER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WA_SYMPHONY_OF_LOVER = gettick() + battle_config.WOE_K_DELAY_WA_SYMPHONY_OF_LOVER;
				else
					sd->K_CHK_WA_SYMPHONY_OF_LOVER = gettick() + battle_config.K_DELAY_WA_SYMPHONY_OF_LOVER;

				sd->K_LOCK_WA_SYMPHONY_OF_LOVER = 0;
			}
			break;
		case WA_MOONLIT_SERENADE:
			if(DIFF_TICK(sd->K_CHK_WA_MOONLIT_SERENADE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WA_MOONLIT_SERENADE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WA_MOONLIT_SERENADE >= (battle_config.WOE_K_DELAY_WA_MOONLIT_SERENADE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WA_MOONLIT_SERENADE >= (battle_config.K_DELAY_WA_MOONLIT_SERENADE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WA_MOONLIT_SERENADE = sd->K_LOCK_WA_MOONLIT_SERENADE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WA_MOONLIT_SERENADE = gettick() + battle_config.WOE_K_DELAY_WA_MOONLIT_SERENADE;
				else
					sd->K_CHK_WA_MOONLIT_SERENADE = gettick() + battle_config.K_DELAY_WA_MOONLIT_SERENADE;

				sd->K_LOCK_WA_MOONLIT_SERENADE = 0;
			}
			break;
		case MI_RUSH_WINDMILL:
			if(DIFF_TICK(sd->K_CHK_MI_RUSH_WINDMILL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MI_RUSH_WINDMILL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MI_RUSH_WINDMILL >= (battle_config.WOE_K_DELAY_MI_RUSH_WINDMILL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MI_RUSH_WINDMILL >= (battle_config.K_DELAY_MI_RUSH_WINDMILL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MI_RUSH_WINDMILL = sd->K_LOCK_MI_RUSH_WINDMILL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MI_RUSH_WINDMILL = gettick() + battle_config.WOE_K_DELAY_MI_RUSH_WINDMILL;
				else
					sd->K_CHK_MI_RUSH_WINDMILL = gettick() + battle_config.K_DELAY_MI_RUSH_WINDMILL;

				sd->K_LOCK_MI_RUSH_WINDMILL = 0;
			}
			break;
		case MI_ECHOSONG:
			if(DIFF_TICK(sd->K_CHK_MI_ECHOSONG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MI_ECHOSONG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MI_ECHOSONG >= (battle_config.WOE_K_DELAY_MI_ECHOSONG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MI_ECHOSONG >= (battle_config.K_DELAY_MI_ECHOSONG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MI_ECHOSONG = sd->K_LOCK_MI_ECHOSONG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MI_ECHOSONG = gettick() + battle_config.WOE_K_DELAY_MI_ECHOSONG;
				else
					sd->K_CHK_MI_ECHOSONG = gettick() + battle_config.K_DELAY_MI_ECHOSONG;

				sd->K_LOCK_MI_ECHOSONG = 0;
			}
			break;
		case MI_HARMONIZE:
			if(DIFF_TICK(sd->K_CHK_MI_HARMONIZE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_MI_HARMONIZE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_MI_HARMONIZE >= (battle_config.WOE_K_DELAY_MI_HARMONIZE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_MI_HARMONIZE >= (battle_config.K_DELAY_MI_HARMONIZE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_MI_HARMONIZE = sd->K_LOCK_MI_HARMONIZE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_MI_HARMONIZE = gettick() + battle_config.WOE_K_DELAY_MI_HARMONIZE;
				else
					sd->K_CHK_MI_HARMONIZE = gettick() + battle_config.K_DELAY_MI_HARMONIZE;

				sd->K_LOCK_MI_HARMONIZE = 0;
			}
			break;
		case WM_LESSON:
			if(DIFF_TICK(sd->K_CHK_WM_LESSON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_LESSON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_LESSON >= (battle_config.WOE_K_DELAY_WM_LESSON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_LESSON >= (battle_config.K_DELAY_WM_LESSON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_LESSON = sd->K_LOCK_WM_LESSON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_LESSON = gettick() + battle_config.WOE_K_DELAY_WM_LESSON;
				else
					sd->K_CHK_WM_LESSON = gettick() + battle_config.K_DELAY_WM_LESSON;

				sd->K_LOCK_WM_LESSON = 0;
			}
			break;
		case WM_METALICSOUND:
			if(DIFF_TICK(sd->K_CHK_WM_METALICSOUND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_METALICSOUND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_METALICSOUND >= (battle_config.WOE_K_DELAY_WM_METALICSOUND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_METALICSOUND >= (battle_config.K_DELAY_WM_METALICSOUND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_METALICSOUND = sd->K_LOCK_WM_METALICSOUND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_METALICSOUND = gettick() + battle_config.WOE_K_DELAY_WM_METALICSOUND;
				else
					sd->K_CHK_WM_METALICSOUND = gettick() + battle_config.K_DELAY_WM_METALICSOUND;

				sd->K_LOCK_WM_METALICSOUND = 0;
			}
			break;
		case WM_REVERBERATION:
			if(DIFF_TICK(sd->K_CHK_WM_REVERBERATION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_REVERBERATION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_REVERBERATION >= (battle_config.WOE_K_DELAY_WM_REVERBERATION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_REVERBERATION >= (battle_config.K_DELAY_WM_REVERBERATION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_REVERBERATION = sd->K_LOCK_WM_REVERBERATION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_REVERBERATION = gettick() + battle_config.WOE_K_DELAY_WM_REVERBERATION;
				else
					sd->K_CHK_WM_REVERBERATION = gettick() + battle_config.K_DELAY_WM_REVERBERATION;

				sd->K_LOCK_WM_REVERBERATION = 0;
			}
			break;
		case WM_REVERBERATION_MELEE:
			if(DIFF_TICK(sd->K_CHK_WM_REVERBERATION_MELEE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_REVERBERATION_MELEE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_REVERBERATION_MELEE >= (battle_config.WOE_K_DELAY_WM_REVERBERATION_MELEE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_REVERBERATION_MELEE >= (battle_config.K_DELAY_WM_REVERBERATION_MELEE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_REVERBERATION_MELEE = sd->K_LOCK_WM_REVERBERATION_MELEE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_REVERBERATION_MELEE = gettick() + battle_config.WOE_K_DELAY_WM_REVERBERATION_MELEE;
				else
					sd->K_CHK_WM_REVERBERATION_MELEE = gettick() + battle_config.K_DELAY_WM_REVERBERATION_MELEE;

				sd->K_LOCK_WM_REVERBERATION_MELEE = 0;
			}
			break;
		case WM_REVERBERATION_MAGIC:
			if(DIFF_TICK(sd->K_CHK_WM_REVERBERATION_MAGIC,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_REVERBERATION_MAGIC - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_REVERBERATION_MAGIC >= (battle_config.WOE_K_DELAY_WM_REVERBERATION_MAGIC/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_REVERBERATION_MAGIC >= (battle_config.K_DELAY_WM_REVERBERATION_MAGIC/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_REVERBERATION_MAGIC = sd->K_LOCK_WM_REVERBERATION_MAGIC +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_REVERBERATION_MAGIC = gettick() + battle_config.WOE_K_DELAY_WM_REVERBERATION_MAGIC;
				else
					sd->K_CHK_WM_REVERBERATION_MAGIC = gettick() + battle_config.K_DELAY_WM_REVERBERATION_MAGIC;

				sd->K_LOCK_WM_REVERBERATION_MAGIC = 0;
			}
			break;
		case WM_DOMINION_IMPULSE:
			if(DIFF_TICK(sd->K_CHK_WM_DOMINION_IMPULSE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_DOMINION_IMPULSE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_DOMINION_IMPULSE >= (battle_config.WOE_K_DELAY_WM_DOMINION_IMPULSE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_DOMINION_IMPULSE >= (battle_config.K_DELAY_WM_DOMINION_IMPULSE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_DOMINION_IMPULSE = sd->K_LOCK_WM_DOMINION_IMPULSE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_DOMINION_IMPULSE = gettick() + battle_config.WOE_K_DELAY_WM_DOMINION_IMPULSE;
				else
					sd->K_CHK_WM_DOMINION_IMPULSE = gettick() + battle_config.K_DELAY_WM_DOMINION_IMPULSE;

				sd->K_LOCK_WM_DOMINION_IMPULSE = 0;
			}
			break;
		case WM_SEVERE_RAINSTORM:
			if(DIFF_TICK(sd->K_CHK_WM_SEVERE_RAINSTORM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SEVERE_RAINSTORM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SEVERE_RAINSTORM >= (battle_config.WOE_K_DELAY_WM_SEVERE_RAINSTORM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SEVERE_RAINSTORM >= (battle_config.K_DELAY_WM_SEVERE_RAINSTORM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SEVERE_RAINSTORM = sd->K_LOCK_WM_SEVERE_RAINSTORM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SEVERE_RAINSTORM = gettick() + battle_config.WOE_K_DELAY_WM_SEVERE_RAINSTORM;
				else
					sd->K_CHK_WM_SEVERE_RAINSTORM = gettick() + battle_config.K_DELAY_WM_SEVERE_RAINSTORM;

				sd->K_LOCK_WM_SEVERE_RAINSTORM = 0;
			}
			break;
		case WM_SEVERE_RAINSTORM_MELEE:
			if(DIFF_TICK(sd->K_CHK_WM_SEVERE_RAINSTORM_MELEE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SEVERE_RAINSTORM_MELEE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SEVERE_RAINSTORM_MELEE >= (battle_config.WOE_K_DELAY_WM_SEVERE_RAINSTORM_MELEE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SEVERE_RAINSTORM_MELEE >= (battle_config.K_DELAY_WM_SEVERE_RAINSTORM_MELEE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SEVERE_RAINSTORM_MELEE = sd->K_LOCK_WM_SEVERE_RAINSTORM_MELEE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SEVERE_RAINSTORM_MELEE = gettick() + battle_config.WOE_K_DELAY_WM_SEVERE_RAINSTORM_MELEE;
				else
					sd->K_CHK_WM_SEVERE_RAINSTORM_MELEE = gettick() + battle_config.K_DELAY_WM_SEVERE_RAINSTORM_MELEE;

				sd->K_LOCK_WM_SEVERE_RAINSTORM_MELEE = 0;
			}
			break;
		case WM_POEMOFNETHERWORLD:
			if(DIFF_TICK(sd->K_CHK_WM_POEMOFNETHERWORLD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_POEMOFNETHERWORLD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_POEMOFNETHERWORLD >= (battle_config.WOE_K_DELAY_WM_POEMOFNETHERWORLD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_POEMOFNETHERWORLD >= (battle_config.K_DELAY_WM_POEMOFNETHERWORLD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_POEMOFNETHERWORLD = sd->K_LOCK_WM_POEMOFNETHERWORLD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_POEMOFNETHERWORLD = gettick() + battle_config.WOE_K_DELAY_WM_POEMOFNETHERWORLD;
				else
					sd->K_CHK_WM_POEMOFNETHERWORLD = gettick() + battle_config.K_DELAY_WM_POEMOFNETHERWORLD;

				sd->K_LOCK_WM_POEMOFNETHERWORLD = 0;
			}
			break;
		case WM_VOICEOFSIREN:
			if(DIFF_TICK(sd->K_CHK_WM_VOICEOFSIREN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_VOICEOFSIREN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_VOICEOFSIREN >= (battle_config.WOE_K_DELAY_WM_VOICEOFSIREN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_VOICEOFSIREN >= (battle_config.K_DELAY_WM_VOICEOFSIREN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_VOICEOFSIREN = sd->K_LOCK_WM_VOICEOFSIREN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_VOICEOFSIREN = gettick() + battle_config.WOE_K_DELAY_WM_VOICEOFSIREN;
				else
					sd->K_CHK_WM_VOICEOFSIREN = gettick() + battle_config.K_DELAY_WM_VOICEOFSIREN;

				sd->K_LOCK_WM_VOICEOFSIREN = 0;
			}
			break;
		case WM_DEADHILLHERE:
			if(DIFF_TICK(sd->K_CHK_WM_DEADHILLHERE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_DEADHILLHERE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_DEADHILLHERE >= (battle_config.WOE_K_DELAY_WM_DEADHILLHERE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_DEADHILLHERE >= (battle_config.K_DELAY_WM_DEADHILLHERE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_DEADHILLHERE = sd->K_LOCK_WM_DEADHILLHERE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_DEADHILLHERE = gettick() + battle_config.WOE_K_DELAY_WM_DEADHILLHERE;
				else
					sd->K_CHK_WM_DEADHILLHERE = gettick() + battle_config.K_DELAY_WM_DEADHILLHERE;

				sd->K_LOCK_WM_DEADHILLHERE = 0;
			}
			break;
		case WM_LULLABY_DEEPSLEEP:
			if(DIFF_TICK(sd->K_CHK_WM_LULLABY_DEEPSLEEP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_LULLABY_DEEPSLEEP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_LULLABY_DEEPSLEEP >= (battle_config.WOE_K_DELAY_WM_LULLABY_DEEPSLEEP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_LULLABY_DEEPSLEEP >= (battle_config.K_DELAY_WM_LULLABY_DEEPSLEEP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_LULLABY_DEEPSLEEP = sd->K_LOCK_WM_LULLABY_DEEPSLEEP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_LULLABY_DEEPSLEEP = gettick() + battle_config.WOE_K_DELAY_WM_LULLABY_DEEPSLEEP;
				else
					sd->K_CHK_WM_LULLABY_DEEPSLEEP = gettick() + battle_config.K_DELAY_WM_LULLABY_DEEPSLEEP;

				sd->K_LOCK_WM_LULLABY_DEEPSLEEP = 0;
			}
			break;
		case WM_SIRCLEOFNATURE:
			if(DIFF_TICK(sd->K_CHK_WM_SIRCLEOFNATURE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SIRCLEOFNATURE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SIRCLEOFNATURE >= (battle_config.WOE_K_DELAY_WM_SIRCLEOFNATURE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SIRCLEOFNATURE >= (battle_config.K_DELAY_WM_SIRCLEOFNATURE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SIRCLEOFNATURE = sd->K_LOCK_WM_SIRCLEOFNATURE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SIRCLEOFNATURE = gettick() + battle_config.WOE_K_DELAY_WM_SIRCLEOFNATURE;
				else
					sd->K_CHK_WM_SIRCLEOFNATURE = gettick() + battle_config.K_DELAY_WM_SIRCLEOFNATURE;

				sd->K_LOCK_WM_SIRCLEOFNATURE = 0;
			}
			break;
		case WM_RANDOMIZESPELL:
			if(DIFF_TICK(sd->K_CHK_WM_RANDOMIZESPELL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_RANDOMIZESPELL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_RANDOMIZESPELL >= (battle_config.WOE_K_DELAY_WM_RANDOMIZESPELL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_RANDOMIZESPELL >= (battle_config.K_DELAY_WM_RANDOMIZESPELL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_RANDOMIZESPELL = sd->K_LOCK_WM_RANDOMIZESPELL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_RANDOMIZESPELL = gettick() + battle_config.WOE_K_DELAY_WM_RANDOMIZESPELL;
				else
					sd->K_CHK_WM_RANDOMIZESPELL = gettick() + battle_config.K_DELAY_WM_RANDOMIZESPELL;

				sd->K_LOCK_WM_RANDOMIZESPELL = 0;
			}
			break;
		case WM_GLOOMYDAY:
			if(DIFF_TICK(sd->K_CHK_WM_GLOOMYDAY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_GLOOMYDAY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_GLOOMYDAY >= (battle_config.WOE_K_DELAY_WM_GLOOMYDAY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_GLOOMYDAY >= (battle_config.K_DELAY_WM_GLOOMYDAY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_GLOOMYDAY = sd->K_LOCK_WM_GLOOMYDAY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_GLOOMYDAY = gettick() + battle_config.WOE_K_DELAY_WM_GLOOMYDAY;
				else
					sd->K_CHK_WM_GLOOMYDAY = gettick() + battle_config.K_DELAY_WM_GLOOMYDAY;

				sd->K_LOCK_WM_GLOOMYDAY = 0;
			}
			break;
		case WM_GREAT_ECHO:
			if(DIFF_TICK(sd->K_CHK_WM_GREAT_ECHO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_GREAT_ECHO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_GREAT_ECHO >= (battle_config.WOE_K_DELAY_WM_GREAT_ECHO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_GREAT_ECHO >= (battle_config.K_DELAY_WM_GREAT_ECHO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_GREAT_ECHO = sd->K_LOCK_WM_GREAT_ECHO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_GREAT_ECHO = gettick() + battle_config.WOE_K_DELAY_WM_GREAT_ECHO;
				else
					sd->K_CHK_WM_GREAT_ECHO = gettick() + battle_config.K_DELAY_WM_GREAT_ECHO;

				sd->K_LOCK_WM_GREAT_ECHO = 0;
			}
			break;
		case WM_SONG_OF_MANA:
			if(DIFF_TICK(sd->K_CHK_WM_SONG_OF_MANA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SONG_OF_MANA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SONG_OF_MANA >= (battle_config.WOE_K_DELAY_WM_SONG_OF_MANA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SONG_OF_MANA >= (battle_config.K_DELAY_WM_SONG_OF_MANA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SONG_OF_MANA = sd->K_LOCK_WM_SONG_OF_MANA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SONG_OF_MANA = gettick() + battle_config.WOE_K_DELAY_WM_SONG_OF_MANA;
				else
					sd->K_CHK_WM_SONG_OF_MANA = gettick() + battle_config.K_DELAY_WM_SONG_OF_MANA;

				sd->K_LOCK_WM_SONG_OF_MANA = 0;
			}
			break;
		case WM_DANCE_WITH_WUG:
			if(DIFF_TICK(sd->K_CHK_WM_DANCE_WITH_WUG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_DANCE_WITH_WUG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_DANCE_WITH_WUG >= (battle_config.WOE_K_DELAY_WM_DANCE_WITH_WUG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_DANCE_WITH_WUG >= (battle_config.K_DELAY_WM_DANCE_WITH_WUG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_DANCE_WITH_WUG = sd->K_LOCK_WM_DANCE_WITH_WUG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_DANCE_WITH_WUG = gettick() + battle_config.WOE_K_DELAY_WM_DANCE_WITH_WUG;
				else
					sd->K_CHK_WM_DANCE_WITH_WUG = gettick() + battle_config.K_DELAY_WM_DANCE_WITH_WUG;

				sd->K_LOCK_WM_DANCE_WITH_WUG = 0;
			}
			break;
		case WM_SOUND_OF_DESTRUCTION:
			if(DIFF_TICK(sd->K_CHK_WM_SOUND_OF_DESTRUCTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SOUND_OF_DESTRUCTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SOUND_OF_DESTRUCTION >= (battle_config.WOE_K_DELAY_WM_SOUND_OF_DESTRUCTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SOUND_OF_DESTRUCTION >= (battle_config.K_DELAY_WM_SOUND_OF_DESTRUCTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SOUND_OF_DESTRUCTION = sd->K_LOCK_WM_SOUND_OF_DESTRUCTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SOUND_OF_DESTRUCTION = gettick() + battle_config.WOE_K_DELAY_WM_SOUND_OF_DESTRUCTION;
				else
					sd->K_CHK_WM_SOUND_OF_DESTRUCTION = gettick() + battle_config.K_DELAY_WM_SOUND_OF_DESTRUCTION;

				sd->K_LOCK_WM_SOUND_OF_DESTRUCTION = 0;
			}
			break;
		case WM_SATURDAY_NIGHT_FEVER:
			if(DIFF_TICK(sd->K_CHK_WM_SATURDAY_NIGHT_FEVER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_SATURDAY_NIGHT_FEVER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_SATURDAY_NIGHT_FEVER >= (battle_config.WOE_K_DELAY_WM_SATURDAY_NIGHT_FEVER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_SATURDAY_NIGHT_FEVER >= (battle_config.K_DELAY_WM_SATURDAY_NIGHT_FEVER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_SATURDAY_NIGHT_FEVER = sd->K_LOCK_WM_SATURDAY_NIGHT_FEVER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_SATURDAY_NIGHT_FEVER = gettick() + battle_config.WOE_K_DELAY_WM_SATURDAY_NIGHT_FEVER;
				else
					sd->K_CHK_WM_SATURDAY_NIGHT_FEVER = gettick() + battle_config.K_DELAY_WM_SATURDAY_NIGHT_FEVER;

				sd->K_LOCK_WM_SATURDAY_NIGHT_FEVER = 0;
			}
			break;
		case WM_LERADS_DEW:
			if(DIFF_TICK(sd->K_CHK_WM_LERADS_DEW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_LERADS_DEW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_LERADS_DEW >= (battle_config.WOE_K_DELAY_WM_LERADS_DEW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_LERADS_DEW >= (battle_config.K_DELAY_WM_LERADS_DEW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_LERADS_DEW = sd->K_LOCK_WM_LERADS_DEW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_LERADS_DEW = gettick() + battle_config.WOE_K_DELAY_WM_LERADS_DEW;
				else
					sd->K_CHK_WM_LERADS_DEW = gettick() + battle_config.K_DELAY_WM_LERADS_DEW;

				sd->K_LOCK_WM_LERADS_DEW = 0;
			}
			break;
		case WM_MELODYOFSINK:
			if(DIFF_TICK(sd->K_CHK_WM_MELODYOFSINK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_MELODYOFSINK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_MELODYOFSINK >= (battle_config.WOE_K_DELAY_WM_MELODYOFSINK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_MELODYOFSINK >= (battle_config.K_DELAY_WM_MELODYOFSINK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_MELODYOFSINK = sd->K_LOCK_WM_MELODYOFSINK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_MELODYOFSINK = gettick() + battle_config.WOE_K_DELAY_WM_MELODYOFSINK;
				else
					sd->K_CHK_WM_MELODYOFSINK = gettick() + battle_config.K_DELAY_WM_MELODYOFSINK;

				sd->K_LOCK_WM_MELODYOFSINK = 0;
			}
			break;
		case WM_BEYOND_OF_WARCRY:
			if(DIFF_TICK(sd->K_CHK_WM_BEYOND_OF_WARCRY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_BEYOND_OF_WARCRY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_BEYOND_OF_WARCRY >= (battle_config.WOE_K_DELAY_WM_BEYOND_OF_WARCRY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_BEYOND_OF_WARCRY >= (battle_config.K_DELAY_WM_BEYOND_OF_WARCRY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_BEYOND_OF_WARCRY = sd->K_LOCK_WM_BEYOND_OF_WARCRY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_BEYOND_OF_WARCRY = gettick() + battle_config.WOE_K_DELAY_WM_BEYOND_OF_WARCRY;
				else
					sd->K_CHK_WM_BEYOND_OF_WARCRY = gettick() + battle_config.K_DELAY_WM_BEYOND_OF_WARCRY;

				sd->K_LOCK_WM_BEYOND_OF_WARCRY = 0;
			}
			break;
		case WM_UNLIMITED_HUMMING_VOICE:
			if(DIFF_TICK(sd->K_CHK_WM_UNLIMITED_HUMMING_VOICE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_UNLIMITED_HUMMING_VOICE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_UNLIMITED_HUMMING_VOICE >= (battle_config.WOE_K_DELAY_WM_UNLIMITED_HUMMING_VOICE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_UNLIMITED_HUMMING_VOICE >= (battle_config.K_DELAY_WM_UNLIMITED_HUMMING_VOICE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_UNLIMITED_HUMMING_VOICE = sd->K_LOCK_WM_UNLIMITED_HUMMING_VOICE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_UNLIMITED_HUMMING_VOICE = gettick() + battle_config.WOE_K_DELAY_WM_UNLIMITED_HUMMING_VOICE;
				else
					sd->K_CHK_WM_UNLIMITED_HUMMING_VOICE = gettick() + battle_config.K_DELAY_WM_UNLIMITED_HUMMING_VOICE;

				sd->K_LOCK_WM_UNLIMITED_HUMMING_VOICE = 0;
			}
			break;
		case SO_FIREWALK:
			if(DIFF_TICK(sd->K_CHK_SO_FIREWALK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_FIREWALK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_FIREWALK >= (battle_config.WOE_K_DELAY_SO_FIREWALK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_FIREWALK >= (battle_config.K_DELAY_SO_FIREWALK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_FIREWALK = sd->K_LOCK_SO_FIREWALK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_FIREWALK = gettick() + battle_config.WOE_K_DELAY_SO_FIREWALK;
				else
					sd->K_CHK_SO_FIREWALK = gettick() + battle_config.K_DELAY_SO_FIREWALK;

				sd->K_LOCK_SO_FIREWALK = 0;
			}
			break;
		case SO_ELECTRICWALK:
			if(DIFF_TICK(sd->K_CHK_SO_ELECTRICWALK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_ELECTRICWALK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_ELECTRICWALK >= (battle_config.WOE_K_DELAY_SO_ELECTRICWALK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_ELECTRICWALK >= (battle_config.K_DELAY_SO_ELECTRICWALK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_ELECTRICWALK = sd->K_LOCK_SO_ELECTRICWALK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_ELECTRICWALK = gettick() + battle_config.WOE_K_DELAY_SO_ELECTRICWALK;
				else
					sd->K_CHK_SO_ELECTRICWALK = gettick() + battle_config.K_DELAY_SO_ELECTRICWALK;

				sd->K_LOCK_SO_ELECTRICWALK = 0;
			}
			break;
		case SO_SPELLFIST:
			if(DIFF_TICK(sd->K_CHK_SO_SPELLFIST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_SPELLFIST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_SPELLFIST >= (battle_config.WOE_K_DELAY_SO_SPELLFIST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_SPELLFIST >= (battle_config.K_DELAY_SO_SPELLFIST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_SPELLFIST = sd->K_LOCK_SO_SPELLFIST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_SPELLFIST = gettick() + battle_config.WOE_K_DELAY_SO_SPELLFIST;
				else
					sd->K_CHK_SO_SPELLFIST = gettick() + battle_config.K_DELAY_SO_SPELLFIST;

				sd->K_LOCK_SO_SPELLFIST = 0;
			}
			break;
		case SO_EARTHGRAVE:
			if(DIFF_TICK(sd->K_CHK_SO_EARTHGRAVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EARTHGRAVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EARTHGRAVE >= (battle_config.WOE_K_DELAY_SO_EARTHGRAVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EARTHGRAVE >= (battle_config.K_DELAY_SO_EARTHGRAVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EARTHGRAVE = sd->K_LOCK_SO_EARTHGRAVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EARTHGRAVE = gettick() + battle_config.WOE_K_DELAY_SO_EARTHGRAVE;
				else
					sd->K_CHK_SO_EARTHGRAVE = gettick() + battle_config.K_DELAY_SO_EARTHGRAVE;

				sd->K_LOCK_SO_EARTHGRAVE = 0;
			}
			break;
		case SO_DIAMONDDUST:
			if(DIFF_TICK(sd->K_CHK_SO_DIAMONDDUST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_DIAMONDDUST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_DIAMONDDUST >= (battle_config.WOE_K_DELAY_SO_DIAMONDDUST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_DIAMONDDUST >= (battle_config.K_DELAY_SO_DIAMONDDUST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_DIAMONDDUST = sd->K_LOCK_SO_DIAMONDDUST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_DIAMONDDUST = gettick() + battle_config.WOE_K_DELAY_SO_DIAMONDDUST;
				else
					sd->K_CHK_SO_DIAMONDDUST = gettick() + battle_config.K_DELAY_SO_DIAMONDDUST;

				sd->K_LOCK_SO_DIAMONDDUST = 0;
			}
			break;
		case SO_POISON_BUSTER:
			if(DIFF_TICK(sd->K_CHK_SO_POISON_BUSTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_POISON_BUSTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_POISON_BUSTER >= (battle_config.WOE_K_DELAY_SO_POISON_BUSTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_POISON_BUSTER >= (battle_config.K_DELAY_SO_POISON_BUSTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_POISON_BUSTER = sd->K_LOCK_SO_POISON_BUSTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_POISON_BUSTER = gettick() + battle_config.WOE_K_DELAY_SO_POISON_BUSTER;
				else
					sd->K_CHK_SO_POISON_BUSTER = gettick() + battle_config.K_DELAY_SO_POISON_BUSTER;

				sd->K_LOCK_SO_POISON_BUSTER = 0;
			}
			break;
		case SO_PSYCHIC_WAVE:
			if(DIFF_TICK(sd->K_CHK_SO_PSYCHIC_WAVE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_PSYCHIC_WAVE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_PSYCHIC_WAVE >= (battle_config.WOE_K_DELAY_SO_PSYCHIC_WAVE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_PSYCHIC_WAVE >= (battle_config.K_DELAY_SO_PSYCHIC_WAVE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_PSYCHIC_WAVE = sd->K_LOCK_SO_PSYCHIC_WAVE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_PSYCHIC_WAVE = gettick() + battle_config.WOE_K_DELAY_SO_PSYCHIC_WAVE;
				else
					sd->K_CHK_SO_PSYCHIC_WAVE = gettick() + battle_config.K_DELAY_SO_PSYCHIC_WAVE;

				sd->K_LOCK_SO_PSYCHIC_WAVE = 0;
			}
			break;
		case SO_CLOUD_KILL:
			if(DIFF_TICK(sd->K_CHK_SO_CLOUD_KILL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_CLOUD_KILL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_CLOUD_KILL >= (battle_config.WOE_K_DELAY_SO_CLOUD_KILL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_CLOUD_KILL >= (battle_config.K_DELAY_SO_CLOUD_KILL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_CLOUD_KILL = sd->K_LOCK_SO_CLOUD_KILL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_CLOUD_KILL = gettick() + battle_config.WOE_K_DELAY_SO_CLOUD_KILL;
				else
					sd->K_CHK_SO_CLOUD_KILL = gettick() + battle_config.K_DELAY_SO_CLOUD_KILL;

				sd->K_LOCK_SO_CLOUD_KILL = 0;
			}
			break;
		case SO_STRIKING:
			if(DIFF_TICK(sd->K_CHK_SO_STRIKING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_STRIKING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_STRIKING >= (battle_config.WOE_K_DELAY_SO_STRIKING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_STRIKING >= (battle_config.K_DELAY_SO_STRIKING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_STRIKING = sd->K_LOCK_SO_STRIKING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_STRIKING = gettick() + battle_config.WOE_K_DELAY_SO_STRIKING;
				else
					sd->K_CHK_SO_STRIKING = gettick() + battle_config.K_DELAY_SO_STRIKING;

				sd->K_LOCK_SO_STRIKING = 0;
			}
			break;
		case SO_WARMER:
			if(DIFF_TICK(sd->K_CHK_SO_WARMER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_WARMER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_WARMER >= (battle_config.WOE_K_DELAY_SO_WARMER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_WARMER >= (battle_config.K_DELAY_SO_WARMER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_WARMER = sd->K_LOCK_SO_WARMER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_WARMER = gettick() + battle_config.WOE_K_DELAY_SO_WARMER;
				else
					sd->K_CHK_SO_WARMER = gettick() + battle_config.K_DELAY_SO_WARMER;

				sd->K_LOCK_SO_WARMER = 0;
			}
			break;
		case SO_VACUUM_EXTREME:
			if(DIFF_TICK(sd->K_CHK_SO_VACUUM_EXTREME,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_VACUUM_EXTREME - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_VACUUM_EXTREME >= (battle_config.WOE_K_DELAY_SO_VACUUM_EXTREME/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_VACUUM_EXTREME >= (battle_config.K_DELAY_SO_VACUUM_EXTREME/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_VACUUM_EXTREME = sd->K_LOCK_SO_VACUUM_EXTREME +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_VACUUM_EXTREME = gettick() + battle_config.WOE_K_DELAY_SO_VACUUM_EXTREME;
				else
					sd->K_CHK_SO_VACUUM_EXTREME = gettick() + battle_config.K_DELAY_SO_VACUUM_EXTREME;

				sd->K_LOCK_SO_VACUUM_EXTREME = 0;
			}
			break;
		case SO_VARETYR_SPEAR:
			if(DIFF_TICK(sd->K_CHK_SO_VARETYR_SPEAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_VARETYR_SPEAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_VARETYR_SPEAR >= (battle_config.WOE_K_DELAY_SO_VARETYR_SPEAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_VARETYR_SPEAR >= (battle_config.K_DELAY_SO_VARETYR_SPEAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_VARETYR_SPEAR = sd->K_LOCK_SO_VARETYR_SPEAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_VARETYR_SPEAR = gettick() + battle_config.WOE_K_DELAY_SO_VARETYR_SPEAR;
				else
					sd->K_CHK_SO_VARETYR_SPEAR = gettick() + battle_config.K_DELAY_SO_VARETYR_SPEAR;

				sd->K_LOCK_SO_VARETYR_SPEAR = 0;
			}
			break;
		case SO_ARRULLO:
			if(DIFF_TICK(sd->K_CHK_SO_ARRULLO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_ARRULLO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_ARRULLO >= (battle_config.WOE_K_DELAY_SO_ARRULLO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_ARRULLO >= (battle_config.K_DELAY_SO_ARRULLO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_ARRULLO = sd->K_LOCK_SO_ARRULLO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_ARRULLO = gettick() + battle_config.WOE_K_DELAY_SO_ARRULLO;
				else
					sd->K_CHK_SO_ARRULLO = gettick() + battle_config.K_DELAY_SO_ARRULLO;

				sd->K_LOCK_SO_ARRULLO = 0;
			}
			break;
		case SO_EL_CONTROL:
			if(DIFF_TICK(sd->K_CHK_SO_EL_CONTROL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EL_CONTROL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EL_CONTROL >= (battle_config.WOE_K_DELAY_SO_EL_CONTROL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EL_CONTROL >= (battle_config.K_DELAY_SO_EL_CONTROL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EL_CONTROL = sd->K_LOCK_SO_EL_CONTROL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EL_CONTROL = gettick() + battle_config.WOE_K_DELAY_SO_EL_CONTROL;
				else
					sd->K_CHK_SO_EL_CONTROL = gettick() + battle_config.K_DELAY_SO_EL_CONTROL;

				sd->K_LOCK_SO_EL_CONTROL = 0;
			}
			break;
		case SO_EL_ACTION:
			if(DIFF_TICK(sd->K_CHK_SO_EL_ACTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EL_ACTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EL_ACTION >= (battle_config.WOE_K_DELAY_SO_EL_ACTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EL_ACTION >= (battle_config.K_DELAY_SO_EL_ACTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EL_ACTION = sd->K_LOCK_SO_EL_ACTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EL_ACTION = gettick() + battle_config.WOE_K_DELAY_SO_EL_ACTION;
				else
					sd->K_CHK_SO_EL_ACTION = gettick() + battle_config.K_DELAY_SO_EL_ACTION;

				sd->K_LOCK_SO_EL_ACTION = 0;
			}
			break;
		case SO_EL_ANALYSIS:
			if(DIFF_TICK(sd->K_CHK_SO_EL_ANALYSIS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EL_ANALYSIS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EL_ANALYSIS >= (battle_config.WOE_K_DELAY_SO_EL_ANALYSIS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EL_ANALYSIS >= (battle_config.K_DELAY_SO_EL_ANALYSIS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EL_ANALYSIS = sd->K_LOCK_SO_EL_ANALYSIS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EL_ANALYSIS = gettick() + battle_config.WOE_K_DELAY_SO_EL_ANALYSIS;
				else
					sd->K_CHK_SO_EL_ANALYSIS = gettick() + battle_config.K_DELAY_SO_EL_ANALYSIS;

				sd->K_LOCK_SO_EL_ANALYSIS = 0;
			}
			break;
		case SO_EL_SYMPATHY:
			if(DIFF_TICK(sd->K_CHK_SO_EL_SYMPATHY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EL_SYMPATHY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EL_SYMPATHY >= (battle_config.WOE_K_DELAY_SO_EL_SYMPATHY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EL_SYMPATHY >= (battle_config.K_DELAY_SO_EL_SYMPATHY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EL_SYMPATHY = sd->K_LOCK_SO_EL_SYMPATHY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EL_SYMPATHY = gettick() + battle_config.WOE_K_DELAY_SO_EL_SYMPATHY;
				else
					sd->K_CHK_SO_EL_SYMPATHY = gettick() + battle_config.K_DELAY_SO_EL_SYMPATHY;

				sd->K_LOCK_SO_EL_SYMPATHY = 0;
			}
			break;
		case SO_EL_CURE:
			if(DIFF_TICK(sd->K_CHK_SO_EL_CURE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_EL_CURE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_EL_CURE >= (battle_config.WOE_K_DELAY_SO_EL_CURE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_EL_CURE >= (battle_config.K_DELAY_SO_EL_CURE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_EL_CURE = sd->K_LOCK_SO_EL_CURE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_EL_CURE = gettick() + battle_config.WOE_K_DELAY_SO_EL_CURE;
				else
					sd->K_CHK_SO_EL_CURE = gettick() + battle_config.K_DELAY_SO_EL_CURE;

				sd->K_LOCK_SO_EL_CURE = 0;
			}
			break;
		case GN_CART_TORNADO:
			if(DIFF_TICK(sd->K_CHK_GN_CART_TORNADO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_CART_TORNADO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_CART_TORNADO >= (battle_config.WOE_K_DELAY_GN_CART_TORNADO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_CART_TORNADO >= (battle_config.K_DELAY_GN_CART_TORNADO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_CART_TORNADO = sd->K_LOCK_GN_CART_TORNADO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_CART_TORNADO = gettick() + battle_config.WOE_K_DELAY_GN_CART_TORNADO;
				else
					sd->K_CHK_GN_CART_TORNADO = gettick() + battle_config.K_DELAY_GN_CART_TORNADO;

				sd->K_LOCK_GN_CART_TORNADO = 0;
			}
			break;
		case GN_CARTCANNON:
			if(DIFF_TICK(sd->K_CHK_GN_CARTCANNON,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_CARTCANNON - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_CARTCANNON >= (battle_config.WOE_K_DELAY_GN_CARTCANNON/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_CARTCANNON >= (battle_config.K_DELAY_GN_CARTCANNON/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_CARTCANNON = sd->K_LOCK_GN_CARTCANNON +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_CARTCANNON = gettick() + battle_config.WOE_K_DELAY_GN_CARTCANNON;
				else
					sd->K_CHK_GN_CARTCANNON = gettick() + battle_config.K_DELAY_GN_CARTCANNON;

				sd->K_LOCK_GN_CARTCANNON = 0;
			}
			break;
		case GN_THORNS_TRAP:
			if(DIFF_TICK(sd->K_CHK_GN_THORNS_TRAP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_THORNS_TRAP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_THORNS_TRAP >= (battle_config.WOE_K_DELAY_GN_THORNS_TRAP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_THORNS_TRAP >= (battle_config.K_DELAY_GN_THORNS_TRAP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_THORNS_TRAP = sd->K_LOCK_GN_THORNS_TRAP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_THORNS_TRAP = gettick() + battle_config.WOE_K_DELAY_GN_THORNS_TRAP;
				else
					sd->K_CHK_GN_THORNS_TRAP = gettick() + battle_config.K_DELAY_GN_THORNS_TRAP;

				sd->K_LOCK_GN_THORNS_TRAP = 0;
			}
			break;
		case GN_BLOOD_SUCKER:
			if(DIFF_TICK(sd->K_CHK_GN_BLOOD_SUCKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_BLOOD_SUCKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_BLOOD_SUCKER >= (battle_config.WOE_K_DELAY_GN_BLOOD_SUCKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_BLOOD_SUCKER >= (battle_config.K_DELAY_GN_BLOOD_SUCKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_BLOOD_SUCKER = sd->K_LOCK_GN_BLOOD_SUCKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_BLOOD_SUCKER = gettick() + battle_config.WOE_K_DELAY_GN_BLOOD_SUCKER;
				else
					sd->K_CHK_GN_BLOOD_SUCKER = gettick() + battle_config.K_DELAY_GN_BLOOD_SUCKER;

				sd->K_LOCK_GN_BLOOD_SUCKER = 0;
			}
			break;
		case GN_SPORE_EXPLOSION:
			if(DIFF_TICK(sd->K_CHK_GN_SPORE_EXPLOSION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_SPORE_EXPLOSION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_SPORE_EXPLOSION >= (battle_config.WOE_K_DELAY_GN_SPORE_EXPLOSION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_SPORE_EXPLOSION >= (battle_config.K_DELAY_GN_SPORE_EXPLOSION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_SPORE_EXPLOSION = sd->K_LOCK_GN_SPORE_EXPLOSION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_SPORE_EXPLOSION = gettick() + battle_config.WOE_K_DELAY_GN_SPORE_EXPLOSION;
				else
					sd->K_CHK_GN_SPORE_EXPLOSION = gettick() + battle_config.K_DELAY_GN_SPORE_EXPLOSION;

				sd->K_LOCK_GN_SPORE_EXPLOSION = 0;
			}
			break;
		case GN_WALLOFTHORN:
			if(DIFF_TICK(sd->K_CHK_GN_WALLOFTHORN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_WALLOFTHORN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_WALLOFTHORN >= (battle_config.WOE_K_DELAY_GN_WALLOFTHORN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_WALLOFTHORN >= (battle_config.K_DELAY_GN_WALLOFTHORN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_WALLOFTHORN = sd->K_LOCK_GN_WALLOFTHORN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_WALLOFTHORN = gettick() + battle_config.WOE_K_DELAY_GN_WALLOFTHORN;
				else
					sd->K_CHK_GN_WALLOFTHORN = gettick() + battle_config.K_DELAY_GN_WALLOFTHORN;

				sd->K_LOCK_GN_WALLOFTHORN = 0;
			}
			break;
		case GN_CRAZYWEED:
			if(DIFF_TICK(sd->K_CHK_GN_CRAZYWEED,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_CRAZYWEED - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_CRAZYWEED >= (battle_config.WOE_K_DELAY_GN_CRAZYWEED/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_CRAZYWEED >= (battle_config.K_DELAY_GN_CRAZYWEED/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_CRAZYWEED = sd->K_LOCK_GN_CRAZYWEED +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_CRAZYWEED = gettick() + battle_config.WOE_K_DELAY_GN_CRAZYWEED;
				else
					sd->K_CHK_GN_CRAZYWEED = gettick() + battle_config.K_DELAY_GN_CRAZYWEED;

				sd->K_LOCK_GN_CRAZYWEED = 0;
			}
			break;
		case GN_CRAZYWEED_ATK:
			if(DIFF_TICK(sd->K_CHK_GN_CRAZYWEED_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_CRAZYWEED_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_CRAZYWEED_ATK >= (battle_config.WOE_K_DELAY_GN_CRAZYWEED_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_CRAZYWEED_ATK >= (battle_config.K_DELAY_GN_CRAZYWEED_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_CRAZYWEED_ATK = sd->K_LOCK_GN_CRAZYWEED_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_CRAZYWEED_ATK = gettick() + battle_config.WOE_K_DELAY_GN_CRAZYWEED_ATK;
				else
					sd->K_CHK_GN_CRAZYWEED_ATK = gettick() + battle_config.K_DELAY_GN_CRAZYWEED_ATK;

				sd->K_LOCK_GN_CRAZYWEED_ATK = 0;
			}
			break;
		case GN_DEMONIC_FIRE:
			if(DIFF_TICK(sd->K_CHK_GN_DEMONIC_FIRE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_DEMONIC_FIRE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_DEMONIC_FIRE >= (battle_config.WOE_K_DELAY_GN_DEMONIC_FIRE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_DEMONIC_FIRE >= (battle_config.K_DELAY_GN_DEMONIC_FIRE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_DEMONIC_FIRE = sd->K_LOCK_GN_DEMONIC_FIRE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_DEMONIC_FIRE = gettick() + battle_config.WOE_K_DELAY_GN_DEMONIC_FIRE;
				else
					sd->K_CHK_GN_DEMONIC_FIRE = gettick() + battle_config.K_DELAY_GN_DEMONIC_FIRE;

				sd->K_LOCK_GN_DEMONIC_FIRE = 0;
			}
			break;
		case GN_FIRE_EXPANSION:
			if(DIFF_TICK(sd->K_CHK_GN_FIRE_EXPANSION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_FIRE_EXPANSION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_FIRE_EXPANSION >= (battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_FIRE_EXPANSION >= (battle_config.K_DELAY_GN_FIRE_EXPANSION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_FIRE_EXPANSION = sd->K_LOCK_GN_FIRE_EXPANSION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_FIRE_EXPANSION = gettick() + battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION;
				else
					sd->K_CHK_GN_FIRE_EXPANSION = gettick() + battle_config.K_DELAY_GN_FIRE_EXPANSION;

				sd->K_LOCK_GN_FIRE_EXPANSION = 0;
			}
			break;
		case GN_FIRE_EXPANSION_SMOKE_POWDER:
			if(DIFF_TICK(sd->K_CHK_GN_FIRE_EXPANSION_SMOKE_POWDER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_FIRE_EXPANSION_SMOKE_POWDER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_FIRE_EXPANSION_SMOKE_POWDER >= (battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_SMOKE_POWDER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_FIRE_EXPANSION_SMOKE_POWDER >= (battle_config.K_DELAY_GN_FIRE_EXPANSION_SMOKE_POWDER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_FIRE_EXPANSION_SMOKE_POWDER = sd->K_LOCK_GN_FIRE_EXPANSION_SMOKE_POWDER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_FIRE_EXPANSION_SMOKE_POWDER = gettick() + battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_SMOKE_POWDER;
				else
					sd->K_CHK_GN_FIRE_EXPANSION_SMOKE_POWDER = gettick() + battle_config.K_DELAY_GN_FIRE_EXPANSION_SMOKE_POWDER;

				sd->K_LOCK_GN_FIRE_EXPANSION_SMOKE_POWDER = 0;
			}
			break;
		case GN_FIRE_EXPANSION_TEAR_GAS:
			if(DIFF_TICK(sd->K_CHK_GN_FIRE_EXPANSION_TEAR_GAS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_FIRE_EXPANSION_TEAR_GAS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_FIRE_EXPANSION_TEAR_GAS >= (battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_TEAR_GAS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_FIRE_EXPANSION_TEAR_GAS >= (battle_config.K_DELAY_GN_FIRE_EXPANSION_TEAR_GAS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_FIRE_EXPANSION_TEAR_GAS = sd->K_LOCK_GN_FIRE_EXPANSION_TEAR_GAS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_FIRE_EXPANSION_TEAR_GAS = gettick() + battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_TEAR_GAS;
				else
					sd->K_CHK_GN_FIRE_EXPANSION_TEAR_GAS = gettick() + battle_config.K_DELAY_GN_FIRE_EXPANSION_TEAR_GAS;

				sd->K_LOCK_GN_FIRE_EXPANSION_TEAR_GAS = 0;
			}
			break;
		case GN_FIRE_EXPANSION_ACID:
			if(DIFF_TICK(sd->K_CHK_GN_FIRE_EXPANSION_ACID,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_FIRE_EXPANSION_ACID - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_FIRE_EXPANSION_ACID >= (battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_ACID/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_FIRE_EXPANSION_ACID >= (battle_config.K_DELAY_GN_FIRE_EXPANSION_ACID/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_FIRE_EXPANSION_ACID = sd->K_LOCK_GN_FIRE_EXPANSION_ACID +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_FIRE_EXPANSION_ACID = gettick() + battle_config.WOE_K_DELAY_GN_FIRE_EXPANSION_ACID;
				else
					sd->K_CHK_GN_FIRE_EXPANSION_ACID = gettick() + battle_config.K_DELAY_GN_FIRE_EXPANSION_ACID;

				sd->K_LOCK_GN_FIRE_EXPANSION_ACID = 0;
			}
			break;
		case GN_HELLS_PLANT:
			if(DIFF_TICK(sd->K_CHK_GN_HELLS_PLANT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_HELLS_PLANT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_HELLS_PLANT >= (battle_config.WOE_K_DELAY_GN_HELLS_PLANT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_HELLS_PLANT >= (battle_config.K_DELAY_GN_HELLS_PLANT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_HELLS_PLANT = sd->K_LOCK_GN_HELLS_PLANT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_HELLS_PLANT = gettick() + battle_config.WOE_K_DELAY_GN_HELLS_PLANT;
				else
					sd->K_CHK_GN_HELLS_PLANT = gettick() + battle_config.K_DELAY_GN_HELLS_PLANT;

				sd->K_LOCK_GN_HELLS_PLANT = 0;
			}
			break;
		case GN_HELLS_PLANT_ATK:
			if(DIFF_TICK(sd->K_CHK_GN_HELLS_PLANT_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_HELLS_PLANT_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_HELLS_PLANT_ATK >= (battle_config.WOE_K_DELAY_GN_HELLS_PLANT_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_HELLS_PLANT_ATK >= (battle_config.K_DELAY_GN_HELLS_PLANT_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_HELLS_PLANT_ATK = sd->K_LOCK_GN_HELLS_PLANT_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_HELLS_PLANT_ATK = gettick() + battle_config.WOE_K_DELAY_GN_HELLS_PLANT_ATK;
				else
					sd->K_CHK_GN_HELLS_PLANT_ATK = gettick() + battle_config.K_DELAY_GN_HELLS_PLANT_ATK;

				sd->K_LOCK_GN_HELLS_PLANT_ATK = 0;
			}
			break;
		case GN_MANDRAGORA:
			if(DIFF_TICK(sd->K_CHK_GN_MANDRAGORA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_MANDRAGORA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_MANDRAGORA >= (battle_config.WOE_K_DELAY_GN_MANDRAGORA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_MANDRAGORA >= (battle_config.K_DELAY_GN_MANDRAGORA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_MANDRAGORA = sd->K_LOCK_GN_MANDRAGORA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_MANDRAGORA = gettick() + battle_config.WOE_K_DELAY_GN_MANDRAGORA;
				else
					sd->K_CHK_GN_MANDRAGORA = gettick() + battle_config.K_DELAY_GN_MANDRAGORA;

				sd->K_LOCK_GN_MANDRAGORA = 0;
			}
			break;
		case GN_SLINGITEM:
			if(DIFF_TICK(sd->K_CHK_GN_SLINGITEM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_SLINGITEM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_SLINGITEM >= (battle_config.WOE_K_DELAY_GN_SLINGITEM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_SLINGITEM >= (battle_config.K_DELAY_GN_SLINGITEM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_SLINGITEM = sd->K_LOCK_GN_SLINGITEM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_SLINGITEM = gettick() + battle_config.WOE_K_DELAY_GN_SLINGITEM;
				else
					sd->K_CHK_GN_SLINGITEM = gettick() + battle_config.K_DELAY_GN_SLINGITEM;

				sd->K_LOCK_GN_SLINGITEM = 0;
			}
			break;
		case GN_SLINGITEM_RANGEMELEEATK:
			if(DIFF_TICK(sd->K_CHK_GN_SLINGITEM_RANGEMELEEATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_SLINGITEM_RANGEMELEEATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_SLINGITEM_RANGEMELEEATK >= (battle_config.WOE_K_DELAY_GN_SLINGITEM_RANGEMELEEATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_SLINGITEM_RANGEMELEEATK >= (battle_config.K_DELAY_GN_SLINGITEM_RANGEMELEEATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_SLINGITEM_RANGEMELEEATK = sd->K_LOCK_GN_SLINGITEM_RANGEMELEEATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_SLINGITEM_RANGEMELEEATK = gettick() + battle_config.WOE_K_DELAY_GN_SLINGITEM_RANGEMELEEATK;
				else
					sd->K_CHK_GN_SLINGITEM_RANGEMELEEATK = gettick() + battle_config.K_DELAY_GN_SLINGITEM_RANGEMELEEATK;

				sd->K_LOCK_GN_SLINGITEM_RANGEMELEEATK = 0;
			}
			break;
		case GN_CHANGEMATERIAL:
			if(DIFF_TICK(sd->K_CHK_GN_CHANGEMATERIAL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_CHANGEMATERIAL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_CHANGEMATERIAL >= (battle_config.WOE_K_DELAY_GN_CHANGEMATERIAL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_CHANGEMATERIAL >= (battle_config.K_DELAY_GN_CHANGEMATERIAL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_CHANGEMATERIAL = sd->K_LOCK_GN_CHANGEMATERIAL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_CHANGEMATERIAL = gettick() + battle_config.WOE_K_DELAY_GN_CHANGEMATERIAL;
				else
					sd->K_CHK_GN_CHANGEMATERIAL = gettick() + battle_config.K_DELAY_GN_CHANGEMATERIAL;

				sd->K_LOCK_GN_CHANGEMATERIAL = 0;
			}
			break;
		case AB_SECRAMENT:
			if(DIFF_TICK(sd->K_CHK_AB_SECRAMENT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_SECRAMENT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_SECRAMENT >= (battle_config.WOE_K_DELAY_AB_SECRAMENT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_SECRAMENT >= (battle_config.K_DELAY_AB_SECRAMENT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_SECRAMENT = sd->K_LOCK_AB_SECRAMENT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_SECRAMENT = gettick() + battle_config.WOE_K_DELAY_AB_SECRAMENT;
				else
					sd->K_CHK_AB_SECRAMENT = gettick() + battle_config.K_DELAY_AB_SECRAMENT;

				sd->K_LOCK_AB_SECRAMENT = 0;
			}
			break;
		case SR_HOWLINGOFLION:
			if(DIFF_TICK(sd->K_CHK_SR_HOWLINGOFLION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_HOWLINGOFLION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_HOWLINGOFLION >= (battle_config.WOE_K_DELAY_SR_HOWLINGOFLION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_HOWLINGOFLION >= (battle_config.K_DELAY_SR_HOWLINGOFLION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_HOWLINGOFLION = sd->K_LOCK_SR_HOWLINGOFLION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_HOWLINGOFLION = gettick() + battle_config.WOE_K_DELAY_SR_HOWLINGOFLION;
				else
					sd->K_CHK_SR_HOWLINGOFLION = gettick() + battle_config.K_DELAY_SR_HOWLINGOFLION;

				sd->K_LOCK_SR_HOWLINGOFLION = 0;
			}
			break;
		case SR_RIDEINLIGHTNING:
			if(DIFF_TICK(sd->K_CHK_SR_RIDEINLIGHTNING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_RIDEINLIGHTNING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_RIDEINLIGHTNING >= (battle_config.WOE_K_DELAY_SR_RIDEINLIGHTNING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_RIDEINLIGHTNING >= (battle_config.K_DELAY_SR_RIDEINLIGHTNING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_RIDEINLIGHTNING = sd->K_LOCK_SR_RIDEINLIGHTNING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_RIDEINLIGHTNING = gettick() + battle_config.WOE_K_DELAY_SR_RIDEINLIGHTNING;
				else
					sd->K_CHK_SR_RIDEINLIGHTNING = gettick() + battle_config.K_DELAY_SR_RIDEINLIGHTNING;

				sd->K_LOCK_SR_RIDEINLIGHTNING = 0;
			}
			break;
		case LG_OVERBRAND_BRANDISH:
			if(DIFF_TICK(sd->K_CHK_LG_OVERBRAND_BRANDISH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_OVERBRAND_BRANDISH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_OVERBRAND_BRANDISH >= (battle_config.WOE_K_DELAY_LG_OVERBRAND_BRANDISH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_OVERBRAND_BRANDISH >= (battle_config.K_DELAY_LG_OVERBRAND_BRANDISH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_OVERBRAND_BRANDISH = sd->K_LOCK_LG_OVERBRAND_BRANDISH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_OVERBRAND_BRANDISH = gettick() + battle_config.WOE_K_DELAY_LG_OVERBRAND_BRANDISH;
				else
					sd->K_CHK_LG_OVERBRAND_BRANDISH = gettick() + battle_config.K_DELAY_LG_OVERBRAND_BRANDISH;

				sd->K_LOCK_LG_OVERBRAND_BRANDISH = 0;
			}
			break;
		case LG_OVERBRAND_PLUSATK:
			if(DIFF_TICK(sd->K_CHK_LG_OVERBRAND_PLUSATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_LG_OVERBRAND_PLUSATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_LG_OVERBRAND_PLUSATK >= (battle_config.WOE_K_DELAY_LG_OVERBRAND_PLUSATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_LG_OVERBRAND_PLUSATK >= (battle_config.K_DELAY_LG_OVERBRAND_PLUSATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_LG_OVERBRAND_PLUSATK = sd->K_LOCK_LG_OVERBRAND_PLUSATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_LG_OVERBRAND_PLUSATK = gettick() + battle_config.WOE_K_DELAY_LG_OVERBRAND_PLUSATK;
				else
					sd->K_CHK_LG_OVERBRAND_PLUSATK = gettick() + battle_config.K_DELAY_LG_OVERBRAND_PLUSATK;

				sd->K_LOCK_LG_OVERBRAND_PLUSATK = 0;
			}
			break;
		case RL_GLITTERING_GREED:
			if(DIFF_TICK(sd->K_CHK_RL_GLITTERING_GREED,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_GLITTERING_GREED - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_GLITTERING_GREED >= (battle_config.WOE_K_DELAY_RL_GLITTERING_GREED/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_GLITTERING_GREED >= (battle_config.K_DELAY_RL_GLITTERING_GREED/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_GLITTERING_GREED = sd->K_LOCK_RL_GLITTERING_GREED +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_GLITTERING_GREED = gettick() + battle_config.WOE_K_DELAY_RL_GLITTERING_GREED;
				else
					sd->K_CHK_RL_GLITTERING_GREED = gettick() + battle_config.K_DELAY_RL_GLITTERING_GREED;

				sd->K_LOCK_RL_GLITTERING_GREED = 0;
			}
			break;
///		case RL_GLITTERING_GREED_ATK:
///			if(DIFF_TICK(sd->K_CHK_RL_GLITTERING_GREED_ATK,gettick())> 0){
///				if(show_delay){
///					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_GLITTERING_GREED_ATK - gettick())/k);
///					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
///				}
///				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_GLITTERING_GREED_ATK >= (battle_config.WOE_K_DELAY_RL_GLITTERING_GREED_ATK/Acceptable_Packet)))
///					clif_authfail_fd(sd->fd, 9); // Disconnect Player
///				else if(sd->K_LOCK_RL_GLITTERING_GREED_ATK >= (battle_config.K_DELAY_RL_GLITTERING_GREED_ATK/Acceptable_Packet))
///					clif_authfail_fd(sd->fd, 9); // Disconnect Player
///
///				sd->K_LOCK_RL_GLITTERING_GREED_ATK = sd->K_LOCK_RL_GLITTERING_GREED_ATK +1;
///			}
///			else
///			{
///				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
///					sd->K_CHK_RL_GLITTERING_GREED_ATK = gettick() + battle_config.WOE_K_DELAY_RL_GLITTERING_GREED_ATK;
///				else
///					sd->K_CHK_RL_GLITTERING_GREED_ATK = gettick() + battle_config.K_DELAY_RL_GLITTERING_GREED_ATK;
///
///				sd->K_LOCK_RL_GLITTERING_GREED_ATK = 0;
///			}
///			break;
		case RL_RICHS_COIN:
			if(DIFF_TICK(sd->K_CHK_RL_RICHS_COIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_RICHS_COIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_RICHS_COIN >= (battle_config.WOE_K_DELAY_RL_RICHS_COIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_RICHS_COIN >= (battle_config.K_DELAY_RL_RICHS_COIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_RICHS_COIN = sd->K_LOCK_RL_RICHS_COIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_RICHS_COIN = gettick() + battle_config.WOE_K_DELAY_RL_RICHS_COIN;
				else
					sd->K_CHK_RL_RICHS_COIN = gettick() + battle_config.K_DELAY_RL_RICHS_COIN;

				sd->K_LOCK_RL_RICHS_COIN = 0;
			}
			break;
		case RL_MASS_SPIRAL:
			if(DIFF_TICK(sd->K_CHK_RL_MASS_SPIRAL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_MASS_SPIRAL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_MASS_SPIRAL >= (battle_config.WOE_K_DELAY_RL_MASS_SPIRAL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_MASS_SPIRAL >= (battle_config.K_DELAY_RL_MASS_SPIRAL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_MASS_SPIRAL = sd->K_LOCK_RL_MASS_SPIRAL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_MASS_SPIRAL = gettick() + battle_config.WOE_K_DELAY_RL_MASS_SPIRAL;
				else
					sd->K_CHK_RL_MASS_SPIRAL = gettick() + battle_config.K_DELAY_RL_MASS_SPIRAL;

				sd->K_LOCK_RL_MASS_SPIRAL = 0;
			}
			break;
		case RL_BANISHING_BUSTER:
			if(DIFF_TICK(sd->K_CHK_RL_BANISHING_BUSTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_BANISHING_BUSTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_BANISHING_BUSTER >= (battle_config.WOE_K_DELAY_RL_BANISHING_BUSTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_BANISHING_BUSTER >= (battle_config.K_DELAY_RL_BANISHING_BUSTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_BANISHING_BUSTER = sd->K_LOCK_RL_BANISHING_BUSTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_BANISHING_BUSTER = gettick() + battle_config.WOE_K_DELAY_RL_BANISHING_BUSTER;
				else
					sd->K_CHK_RL_BANISHING_BUSTER = gettick() + battle_config.K_DELAY_RL_BANISHING_BUSTER;

				sd->K_LOCK_RL_BANISHING_BUSTER = 0;
			}
			break;
		case RL_B_TRAP:
			if(DIFF_TICK(sd->K_CHK_RL_B_TRAP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_B_TRAP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_B_TRAP >= (battle_config.WOE_K_DELAY_RL_B_TRAP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_B_TRAP >= (battle_config.K_DELAY_RL_B_TRAP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_B_TRAP = sd->K_LOCK_RL_B_TRAP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_B_TRAP = gettick() + battle_config.WOE_K_DELAY_RL_B_TRAP;
				else
					sd->K_CHK_RL_B_TRAP = gettick() + battle_config.K_DELAY_RL_B_TRAP;

				sd->K_LOCK_RL_B_TRAP = 0;
			}
			break;
		case RL_S_STORM:
			if(DIFF_TICK(sd->K_CHK_RL_S_STORM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_S_STORM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_S_STORM >= (battle_config.WOE_K_DELAY_RL_S_STORM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_S_STORM >= (battle_config.K_DELAY_RL_S_STORM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_S_STORM = sd->K_LOCK_RL_S_STORM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_S_STORM = gettick() + battle_config.WOE_K_DELAY_RL_S_STORM;
				else
					sd->K_CHK_RL_S_STORM = gettick() + battle_config.K_DELAY_RL_S_STORM;

				sd->K_LOCK_RL_S_STORM = 0;
			}
			break;
		case RL_E_CHAIN:
			if(DIFF_TICK(sd->K_CHK_RL_E_CHAIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_E_CHAIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_E_CHAIN >= (battle_config.WOE_K_DELAY_RL_E_CHAIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_E_CHAIN >= (battle_config.K_DELAY_RL_E_CHAIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_E_CHAIN = sd->K_LOCK_RL_E_CHAIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_E_CHAIN = gettick() + battle_config.WOE_K_DELAY_RL_E_CHAIN;
				else
					sd->K_CHK_RL_E_CHAIN = gettick() + battle_config.K_DELAY_RL_E_CHAIN;

				sd->K_LOCK_RL_E_CHAIN = 0;
			}
			break;
		case RL_QD_SHOT:
			if(DIFF_TICK(sd->K_CHK_RL_QD_SHOT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_QD_SHOT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_QD_SHOT >= (battle_config.WOE_K_DELAY_RL_QD_SHOT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_QD_SHOT >= (battle_config.K_DELAY_RL_QD_SHOT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_QD_SHOT = sd->K_LOCK_RL_QD_SHOT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_QD_SHOT = gettick() + battle_config.WOE_K_DELAY_RL_QD_SHOT;
				else
					sd->K_CHK_RL_QD_SHOT = gettick() + battle_config.K_DELAY_RL_QD_SHOT;

				sd->K_LOCK_RL_QD_SHOT = 0;
			}
			break;
		case RL_C_MARKER:
			if(DIFF_TICK(sd->K_CHK_RL_C_MARKER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_C_MARKER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_C_MARKER >= (battle_config.WOE_K_DELAY_RL_C_MARKER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_C_MARKER >= (battle_config.K_DELAY_RL_C_MARKER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_C_MARKER = sd->K_LOCK_RL_C_MARKER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_C_MARKER = gettick() + battle_config.WOE_K_DELAY_RL_C_MARKER;
				else
					sd->K_CHK_RL_C_MARKER = gettick() + battle_config.K_DELAY_RL_C_MARKER;

				sd->K_LOCK_RL_C_MARKER = 0;
			}
			break;
		case RL_FIREDANCE:
			if(DIFF_TICK(sd->K_CHK_RL_FIREDANCE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_FIREDANCE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_FIREDANCE >= (battle_config.WOE_K_DELAY_RL_FIREDANCE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_FIREDANCE >= (battle_config.K_DELAY_RL_FIREDANCE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_FIREDANCE = sd->K_LOCK_RL_FIREDANCE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_FIREDANCE = gettick() + battle_config.WOE_K_DELAY_RL_FIREDANCE;
				else
					sd->K_CHK_RL_FIREDANCE = gettick() + battle_config.K_DELAY_RL_FIREDANCE;

				sd->K_LOCK_RL_FIREDANCE = 0;
			}
			break;
		case RL_H_MINE:
			if(DIFF_TICK(sd->K_CHK_RL_H_MINE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_H_MINE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_H_MINE >= (battle_config.WOE_K_DELAY_RL_H_MINE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_H_MINE >= (battle_config.K_DELAY_RL_H_MINE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_H_MINE = sd->K_LOCK_RL_H_MINE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_H_MINE = gettick() + battle_config.WOE_K_DELAY_RL_H_MINE;
				else
					sd->K_CHK_RL_H_MINE = gettick() + battle_config.K_DELAY_RL_H_MINE;

				sd->K_LOCK_RL_H_MINE = 0;
			}
			break;
		case RL_P_ALTER:
			if(DIFF_TICK(sd->K_CHK_RL_P_ALTER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_P_ALTER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_P_ALTER >= (battle_config.WOE_K_DELAY_RL_P_ALTER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_P_ALTER >= (battle_config.K_DELAY_RL_P_ALTER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_P_ALTER = sd->K_LOCK_RL_P_ALTER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_P_ALTER = gettick() + battle_config.WOE_K_DELAY_RL_P_ALTER;
				else
					sd->K_CHK_RL_P_ALTER = gettick() + battle_config.K_DELAY_RL_P_ALTER;

				sd->K_LOCK_RL_P_ALTER = 0;
			}
			break;
		case RL_FALLEN_ANGEL:
			if(DIFF_TICK(sd->K_CHK_RL_FALLEN_ANGEL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_FALLEN_ANGEL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_FALLEN_ANGEL >= (battle_config.WOE_K_DELAY_RL_FALLEN_ANGEL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_FALLEN_ANGEL >= (battle_config.K_DELAY_RL_FALLEN_ANGEL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_FALLEN_ANGEL = sd->K_LOCK_RL_FALLEN_ANGEL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_FALLEN_ANGEL = gettick() + battle_config.WOE_K_DELAY_RL_FALLEN_ANGEL;
				else
					sd->K_CHK_RL_FALLEN_ANGEL = gettick() + battle_config.K_DELAY_RL_FALLEN_ANGEL;

				sd->K_LOCK_RL_FALLEN_ANGEL = 0;
			}
			break;
		case RL_R_TRIP:
			if(DIFF_TICK(sd->K_CHK_RL_R_TRIP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_R_TRIP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_R_TRIP >= (battle_config.WOE_K_DELAY_RL_R_TRIP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_R_TRIP >= (battle_config.K_DELAY_RL_R_TRIP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_R_TRIP = sd->K_LOCK_RL_R_TRIP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_R_TRIP = gettick() + battle_config.WOE_K_DELAY_RL_R_TRIP;
				else
					sd->K_CHK_RL_R_TRIP = gettick() + battle_config.K_DELAY_RL_R_TRIP;

				sd->K_LOCK_RL_R_TRIP = 0;
			}
			break;
		case RL_R_TRIP_PLUSATK:
			if(DIFF_TICK(sd->K_CHK_RL_R_TRIP_PLUSATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_R_TRIP_PLUSATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_R_TRIP_PLUSATK >= (battle_config.WOE_K_DELAY_RL_R_TRIP_PLUSATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_R_TRIP_PLUSATK >= (battle_config.K_DELAY_RL_R_TRIP_PLUSATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_R_TRIP_PLUSATK = sd->K_LOCK_RL_R_TRIP_PLUSATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_R_TRIP_PLUSATK = gettick() + battle_config.WOE_K_DELAY_RL_R_TRIP_PLUSATK;
				else
					sd->K_CHK_RL_R_TRIP_PLUSATK = gettick() + battle_config.K_DELAY_RL_R_TRIP_PLUSATK;

				sd->K_LOCK_RL_R_TRIP_PLUSATK = 0;
			}
			break;
		case RL_D_TAIL:
			if(DIFF_TICK(sd->K_CHK_RL_D_TAIL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_D_TAIL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_D_TAIL >= (battle_config.WOE_K_DELAY_RL_D_TAIL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_D_TAIL >= (battle_config.K_DELAY_RL_D_TAIL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_D_TAIL = sd->K_LOCK_RL_D_TAIL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_D_TAIL = gettick() + battle_config.WOE_K_DELAY_RL_D_TAIL;
				else
					sd->K_CHK_RL_D_TAIL = gettick() + battle_config.K_DELAY_RL_D_TAIL;

				sd->K_LOCK_RL_D_TAIL = 0;
			}
			break;
		case RL_FIRE_RAIN:
			if(DIFF_TICK(sd->K_CHK_RL_FIRE_RAIN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_FIRE_RAIN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_FIRE_RAIN >= (battle_config.WOE_K_DELAY_RL_FIRE_RAIN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_FIRE_RAIN >= (battle_config.K_DELAY_RL_FIRE_RAIN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_FIRE_RAIN = sd->K_LOCK_RL_FIRE_RAIN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_FIRE_RAIN = gettick() + battle_config.WOE_K_DELAY_RL_FIRE_RAIN;
				else
					sd->K_CHK_RL_FIRE_RAIN = gettick() + battle_config.K_DELAY_RL_FIRE_RAIN;

				sd->K_LOCK_RL_FIRE_RAIN = 0;
			}
			break;
		case RL_HEAT_BARREL:
			if(DIFF_TICK(sd->K_CHK_RL_HEAT_BARREL,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_HEAT_BARREL - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_HEAT_BARREL >= (battle_config.WOE_K_DELAY_RL_HEAT_BARREL/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_HEAT_BARREL >= (battle_config.K_DELAY_RL_HEAT_BARREL/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_HEAT_BARREL = sd->K_LOCK_RL_HEAT_BARREL +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_HEAT_BARREL = gettick() + battle_config.WOE_K_DELAY_RL_HEAT_BARREL;
				else
					sd->K_CHK_RL_HEAT_BARREL = gettick() + battle_config.K_DELAY_RL_HEAT_BARREL;

				sd->K_LOCK_RL_HEAT_BARREL = 0;
			}
			break;
		case RL_AM_BLAST:
			if(DIFF_TICK(sd->K_CHK_RL_AM_BLAST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_AM_BLAST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_AM_BLAST >= (battle_config.WOE_K_DELAY_RL_AM_BLAST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_AM_BLAST >= (battle_config.K_DELAY_RL_AM_BLAST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_AM_BLAST = sd->K_LOCK_RL_AM_BLAST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_AM_BLAST = gettick() + battle_config.WOE_K_DELAY_RL_AM_BLAST;
				else
					sd->K_CHK_RL_AM_BLAST = gettick() + battle_config.K_DELAY_RL_AM_BLAST;

				sd->K_LOCK_RL_AM_BLAST = 0;
			}
			break;
		case RL_SLUGSHOT:
			if(DIFF_TICK(sd->K_CHK_RL_SLUGSHOT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_SLUGSHOT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_SLUGSHOT >= (battle_config.WOE_K_DELAY_RL_SLUGSHOT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_SLUGSHOT >= (battle_config.K_DELAY_RL_SLUGSHOT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_SLUGSHOT = sd->K_LOCK_RL_SLUGSHOT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_SLUGSHOT = gettick() + battle_config.WOE_K_DELAY_RL_SLUGSHOT;
				else
					sd->K_CHK_RL_SLUGSHOT = gettick() + battle_config.K_DELAY_RL_SLUGSHOT;

				sd->K_LOCK_RL_SLUGSHOT = 0;
			}
			break;
		case RL_HAMMER_OF_GOD:
			if(DIFF_TICK(sd->K_CHK_RL_HAMMER_OF_GOD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_HAMMER_OF_GOD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_HAMMER_OF_GOD >= (battle_config.WOE_K_DELAY_RL_HAMMER_OF_GOD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_HAMMER_OF_GOD >= (battle_config.K_DELAY_RL_HAMMER_OF_GOD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_HAMMER_OF_GOD = sd->K_LOCK_RL_HAMMER_OF_GOD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_HAMMER_OF_GOD = gettick() + battle_config.WOE_K_DELAY_RL_HAMMER_OF_GOD;
				else
					sd->K_CHK_RL_HAMMER_OF_GOD = gettick() + battle_config.K_DELAY_RL_HAMMER_OF_GOD;

				sd->K_LOCK_RL_HAMMER_OF_GOD = 0;
			}
			break;
		case RL_B_FLICKER_ATK:
			if(DIFF_TICK(sd->K_CHK_RL_B_FLICKER_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RL_B_FLICKER_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RL_B_FLICKER_ATK >= (battle_config.WOE_K_DELAY_RL_B_FLICKER_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RL_B_FLICKER_ATK >= (battle_config.K_DELAY_RL_B_FLICKER_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RL_B_FLICKER_ATK = sd->K_LOCK_RL_B_FLICKER_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RL_B_FLICKER_ATK = gettick() + battle_config.WOE_K_DELAY_RL_B_FLICKER_ATK;
				else
					sd->K_CHK_RL_B_FLICKER_ATK = gettick() + battle_config.K_DELAY_RL_B_FLICKER_ATK;

				sd->K_LOCK_RL_B_FLICKER_ATK = 0;
			}
			break;
		case KO_YAMIKUMO:
			if(DIFF_TICK(sd->K_CHK_KO_YAMIKUMO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_YAMIKUMO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_YAMIKUMO >= (battle_config.WOE_K_DELAY_KO_YAMIKUMO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_YAMIKUMO >= (battle_config.K_DELAY_KO_YAMIKUMO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_YAMIKUMO = sd->K_LOCK_KO_YAMIKUMO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_YAMIKUMO = gettick() + battle_config.WOE_K_DELAY_KO_YAMIKUMO;
				else
					sd->K_CHK_KO_YAMIKUMO = gettick() + battle_config.K_DELAY_KO_YAMIKUMO;

				sd->K_LOCK_KO_YAMIKUMO = 0;
			}
			break;
		case KO_JYUMONJIKIRI:
			if(DIFF_TICK(sd->K_CHK_KO_JYUMONJIKIRI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_JYUMONJIKIRI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_JYUMONJIKIRI >= (battle_config.WOE_K_DELAY_KO_JYUMONJIKIRI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_JYUMONJIKIRI >= (battle_config.K_DELAY_KO_JYUMONJIKIRI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_JYUMONJIKIRI = sd->K_LOCK_KO_JYUMONJIKIRI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_JYUMONJIKIRI = gettick() + battle_config.WOE_K_DELAY_KO_JYUMONJIKIRI;
				else
					sd->K_CHK_KO_JYUMONJIKIRI = gettick() + battle_config.K_DELAY_KO_JYUMONJIKIRI;

				sd->K_LOCK_KO_JYUMONJIKIRI = 0;
			}
			break;
		case KO_SETSUDAN:
			if(DIFF_TICK(sd->K_CHK_KO_SETSUDAN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_SETSUDAN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_SETSUDAN >= (battle_config.WOE_K_DELAY_KO_SETSUDAN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_SETSUDAN >= (battle_config.K_DELAY_KO_SETSUDAN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_SETSUDAN = sd->K_LOCK_KO_SETSUDAN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_SETSUDAN = gettick() + battle_config.WOE_K_DELAY_KO_SETSUDAN;
				else
					sd->K_CHK_KO_SETSUDAN = gettick() + battle_config.K_DELAY_KO_SETSUDAN;

				sd->K_LOCK_KO_SETSUDAN = 0;
			}
			break;
		case KO_BAKURETSU:
			if(DIFF_TICK(sd->K_CHK_KO_BAKURETSU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_BAKURETSU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_BAKURETSU >= (battle_config.WOE_K_DELAY_KO_BAKURETSU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_BAKURETSU >= (battle_config.K_DELAY_KO_BAKURETSU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_BAKURETSU = sd->K_LOCK_KO_BAKURETSU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_BAKURETSU = gettick() + battle_config.WOE_K_DELAY_KO_BAKURETSU;
				else
					sd->K_CHK_KO_BAKURETSU = gettick() + battle_config.K_DELAY_KO_BAKURETSU;

				sd->K_LOCK_KO_BAKURETSU = 0;
			}
			break;
		case KO_HAPPOKUNAI:
			if(DIFF_TICK(sd->K_CHK_KO_HAPPOKUNAI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_HAPPOKUNAI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_HAPPOKUNAI >= (battle_config.WOE_K_DELAY_KO_HAPPOKUNAI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_HAPPOKUNAI >= (battle_config.K_DELAY_KO_HAPPOKUNAI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_HAPPOKUNAI = sd->K_LOCK_KO_HAPPOKUNAI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_HAPPOKUNAI = gettick() + battle_config.WOE_K_DELAY_KO_HAPPOKUNAI;
				else
					sd->K_CHK_KO_HAPPOKUNAI = gettick() + battle_config.K_DELAY_KO_HAPPOKUNAI;

				sd->K_LOCK_KO_HAPPOKUNAI = 0;
			}
			break;
		case KO_MUCHANAGE:
			if(DIFF_TICK(sd->K_CHK_KO_MUCHANAGE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_MUCHANAGE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_MUCHANAGE >= (battle_config.WOE_K_DELAY_KO_MUCHANAGE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_MUCHANAGE >= (battle_config.K_DELAY_KO_MUCHANAGE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_MUCHANAGE = sd->K_LOCK_KO_MUCHANAGE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_MUCHANAGE = gettick() + battle_config.WOE_K_DELAY_KO_MUCHANAGE;
				else
					sd->K_CHK_KO_MUCHANAGE = gettick() + battle_config.K_DELAY_KO_MUCHANAGE;

				sd->K_LOCK_KO_MUCHANAGE = 0;
			}
			break;
		case KO_HUUMARANKA:
			if(DIFF_TICK(sd->K_CHK_KO_HUUMARANKA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_HUUMARANKA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_HUUMARANKA >= (battle_config.WOE_K_DELAY_KO_HUUMARANKA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_HUUMARANKA >= (battle_config.K_DELAY_KO_HUUMARANKA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_HUUMARANKA = sd->K_LOCK_KO_HUUMARANKA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_HUUMARANKA = gettick() + battle_config.WOE_K_DELAY_KO_HUUMARANKA;
				else
					sd->K_CHK_KO_HUUMARANKA = gettick() + battle_config.K_DELAY_KO_HUUMARANKA;

				sd->K_LOCK_KO_HUUMARANKA = 0;
			}
			break;
		case KO_MAKIBISHI:
			if(DIFF_TICK(sd->K_CHK_KO_MAKIBISHI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_MAKIBISHI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_MAKIBISHI >= (battle_config.WOE_K_DELAY_KO_MAKIBISHI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_MAKIBISHI >= (battle_config.K_DELAY_KO_MAKIBISHI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_MAKIBISHI = sd->K_LOCK_KO_MAKIBISHI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_MAKIBISHI = gettick() + battle_config.WOE_K_DELAY_KO_MAKIBISHI;
				else
					sd->K_CHK_KO_MAKIBISHI = gettick() + battle_config.K_DELAY_KO_MAKIBISHI;

				sd->K_LOCK_KO_MAKIBISHI = 0;
			}
			break;
		case KO_MEIKYOUSISUI:
			if(DIFF_TICK(sd->K_CHK_KO_MEIKYOUSISUI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_MEIKYOUSISUI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_MEIKYOUSISUI >= (battle_config.WOE_K_DELAY_KO_MEIKYOUSISUI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_MEIKYOUSISUI >= (battle_config.K_DELAY_KO_MEIKYOUSISUI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_MEIKYOUSISUI = sd->K_LOCK_KO_MEIKYOUSISUI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_MEIKYOUSISUI = gettick() + battle_config.WOE_K_DELAY_KO_MEIKYOUSISUI;
				else
					sd->K_CHK_KO_MEIKYOUSISUI = gettick() + battle_config.K_DELAY_KO_MEIKYOUSISUI;

				sd->K_LOCK_KO_MEIKYOUSISUI = 0;
			}
			break;
		case KO_ZANZOU:
			if(DIFF_TICK(sd->K_CHK_KO_ZANZOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_ZANZOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_ZANZOU >= (battle_config.WOE_K_DELAY_KO_ZANZOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_ZANZOU >= (battle_config.K_DELAY_KO_ZANZOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_ZANZOU = sd->K_LOCK_KO_ZANZOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_ZANZOU = gettick() + battle_config.WOE_K_DELAY_KO_ZANZOU;
				else
					sd->K_CHK_KO_ZANZOU = gettick() + battle_config.K_DELAY_KO_ZANZOU;

				sd->K_LOCK_KO_ZANZOU = 0;
			}
			break;
		case KO_KYOUGAKU:
			if(DIFF_TICK(sd->K_CHK_KO_KYOUGAKU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_KYOUGAKU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_KYOUGAKU >= (battle_config.WOE_K_DELAY_KO_KYOUGAKU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_KYOUGAKU >= (battle_config.K_DELAY_KO_KYOUGAKU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_KYOUGAKU = sd->K_LOCK_KO_KYOUGAKU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_KYOUGAKU = gettick() + battle_config.WOE_K_DELAY_KO_KYOUGAKU;
				else
					sd->K_CHK_KO_KYOUGAKU = gettick() + battle_config.K_DELAY_KO_KYOUGAKU;

				sd->K_LOCK_KO_KYOUGAKU = 0;
			}
			break;
		case KO_JYUSATSU:
			if(DIFF_TICK(sd->K_CHK_KO_JYUSATSU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_JYUSATSU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_JYUSATSU >= (battle_config.WOE_K_DELAY_KO_JYUSATSU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_JYUSATSU >= (battle_config.K_DELAY_KO_JYUSATSU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_JYUSATSU = sd->K_LOCK_KO_JYUSATSU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_JYUSATSU = gettick() + battle_config.WOE_K_DELAY_KO_JYUSATSU;
				else
					sd->K_CHK_KO_JYUSATSU = gettick() + battle_config.K_DELAY_KO_JYUSATSU;

				sd->K_LOCK_KO_JYUSATSU = 0;
			}
			break;
		case KO_KAHU_ENTEN:
			if(DIFF_TICK(sd->K_CHK_KO_KAHU_ENTEN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_KAHU_ENTEN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_KAHU_ENTEN >= (battle_config.WOE_K_DELAY_KO_KAHU_ENTEN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_KAHU_ENTEN >= (battle_config.K_DELAY_KO_KAHU_ENTEN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_KAHU_ENTEN = sd->K_LOCK_KO_KAHU_ENTEN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_KAHU_ENTEN = gettick() + battle_config.WOE_K_DELAY_KO_KAHU_ENTEN;
				else
					sd->K_CHK_KO_KAHU_ENTEN = gettick() + battle_config.K_DELAY_KO_KAHU_ENTEN;

				sd->K_LOCK_KO_KAHU_ENTEN = 0;
			}
			break;
		case KO_HYOUHU_HUBUKI:
			if(DIFF_TICK(sd->K_CHK_KO_HYOUHU_HUBUKI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_HYOUHU_HUBUKI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_HYOUHU_HUBUKI >= (battle_config.WOE_K_DELAY_KO_HYOUHU_HUBUKI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_HYOUHU_HUBUKI >= (battle_config.K_DELAY_KO_HYOUHU_HUBUKI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_HYOUHU_HUBUKI = sd->K_LOCK_KO_HYOUHU_HUBUKI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_HYOUHU_HUBUKI = gettick() + battle_config.WOE_K_DELAY_KO_HYOUHU_HUBUKI;
				else
					sd->K_CHK_KO_HYOUHU_HUBUKI = gettick() + battle_config.K_DELAY_KO_HYOUHU_HUBUKI;

				sd->K_LOCK_KO_HYOUHU_HUBUKI = 0;
			}
			break;
		case KO_KAZEHU_SEIRAN:
			if(DIFF_TICK(sd->K_CHK_KO_KAZEHU_SEIRAN,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_KAZEHU_SEIRAN - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_KAZEHU_SEIRAN >= (battle_config.WOE_K_DELAY_KO_KAZEHU_SEIRAN/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_KAZEHU_SEIRAN >= (battle_config.K_DELAY_KO_KAZEHU_SEIRAN/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_KAZEHU_SEIRAN = sd->K_LOCK_KO_KAZEHU_SEIRAN +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_KAZEHU_SEIRAN = gettick() + battle_config.WOE_K_DELAY_KO_KAZEHU_SEIRAN;
				else
					sd->K_CHK_KO_KAZEHU_SEIRAN = gettick() + battle_config.K_DELAY_KO_KAZEHU_SEIRAN;

				sd->K_LOCK_KO_KAZEHU_SEIRAN = 0;
			}
			break;
		case KO_DOHU_KOUKAI:
			if(DIFF_TICK(sd->K_CHK_KO_DOHU_KOUKAI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_DOHU_KOUKAI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_DOHU_KOUKAI >= (battle_config.WOE_K_DELAY_KO_DOHU_KOUKAI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_DOHU_KOUKAI >= (battle_config.K_DELAY_KO_DOHU_KOUKAI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_DOHU_KOUKAI = sd->K_LOCK_KO_DOHU_KOUKAI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_DOHU_KOUKAI = gettick() + battle_config.WOE_K_DELAY_KO_DOHU_KOUKAI;
				else
					sd->K_CHK_KO_DOHU_KOUKAI = gettick() + battle_config.K_DELAY_KO_DOHU_KOUKAI;

				sd->K_LOCK_KO_DOHU_KOUKAI = 0;
			}
			break;
		case KO_KAIHOU:
			if(DIFF_TICK(sd->K_CHK_KO_KAIHOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_KAIHOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_KAIHOU >= (battle_config.WOE_K_DELAY_KO_KAIHOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_KAIHOU >= (battle_config.K_DELAY_KO_KAIHOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_KAIHOU = sd->K_LOCK_KO_KAIHOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_KAIHOU = gettick() + battle_config.WOE_K_DELAY_KO_KAIHOU;
				else
					sd->K_CHK_KO_KAIHOU = gettick() + battle_config.K_DELAY_KO_KAIHOU;

				sd->K_LOCK_KO_KAIHOU = 0;
			}
			break;
		case KO_ZENKAI:
			if(DIFF_TICK(sd->K_CHK_KO_ZENKAI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_ZENKAI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_ZENKAI >= (battle_config.WOE_K_DELAY_KO_ZENKAI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_ZENKAI >= (battle_config.K_DELAY_KO_ZENKAI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_ZENKAI = sd->K_LOCK_KO_ZENKAI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_ZENKAI = gettick() + battle_config.WOE_K_DELAY_KO_ZENKAI;
				else
					sd->K_CHK_KO_ZENKAI = gettick() + battle_config.K_DELAY_KO_ZENKAI;

				sd->K_LOCK_KO_ZENKAI = 0;
			}
			break;
		case KO_GENWAKU:
			if(DIFF_TICK(sd->K_CHK_KO_GENWAKU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_GENWAKU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_GENWAKU >= (battle_config.WOE_K_DELAY_KO_GENWAKU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_GENWAKU >= (battle_config.K_DELAY_KO_GENWAKU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_GENWAKU = sd->K_LOCK_KO_GENWAKU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_GENWAKU = gettick() + battle_config.WOE_K_DELAY_KO_GENWAKU;
				else
					sd->K_CHK_KO_GENWAKU = gettick() + battle_config.K_DELAY_KO_GENWAKU;

				sd->K_LOCK_KO_GENWAKU = 0;
			}
			break;
		case KO_IZAYOI:
			if(DIFF_TICK(sd->K_CHK_KO_IZAYOI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KO_IZAYOI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KO_IZAYOI >= (battle_config.WOE_K_DELAY_KO_IZAYOI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KO_IZAYOI >= (battle_config.K_DELAY_KO_IZAYOI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KO_IZAYOI = sd->K_LOCK_KO_IZAYOI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KO_IZAYOI = gettick() + battle_config.WOE_K_DELAY_KO_IZAYOI;
				else
					sd->K_CHK_KO_IZAYOI = gettick() + battle_config.K_DELAY_KO_IZAYOI;

				sd->K_LOCK_KO_IZAYOI = 0;
			}
			break;
		case KG_KAGEHUMI:
			if(DIFF_TICK(sd->K_CHK_KG_KAGEHUMI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KG_KAGEHUMI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KG_KAGEHUMI >= (battle_config.WOE_K_DELAY_KG_KAGEHUMI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KG_KAGEHUMI >= (battle_config.K_DELAY_KG_KAGEHUMI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KG_KAGEHUMI = sd->K_LOCK_KG_KAGEHUMI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KG_KAGEHUMI = gettick() + battle_config.WOE_K_DELAY_KG_KAGEHUMI;
				else
					sd->K_CHK_KG_KAGEHUMI = gettick() + battle_config.K_DELAY_KG_KAGEHUMI;

				sd->K_LOCK_KG_KAGEHUMI = 0;
			}
			break;
		case KG_KYOMU:
			if(DIFF_TICK(sd->K_CHK_KG_KYOMU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KG_KYOMU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KG_KYOMU >= (battle_config.WOE_K_DELAY_KG_KYOMU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KG_KYOMU >= (battle_config.K_DELAY_KG_KYOMU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KG_KYOMU = sd->K_LOCK_KG_KYOMU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KG_KYOMU = gettick() + battle_config.WOE_K_DELAY_KG_KYOMU;
				else
					sd->K_CHK_KG_KYOMU = gettick() + battle_config.K_DELAY_KG_KYOMU;

				sd->K_LOCK_KG_KYOMU = 0;
			}
			break;
		case KG_KAGEMUSYA:
			if(DIFF_TICK(sd->K_CHK_KG_KAGEMUSYA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_KG_KAGEMUSYA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_KG_KAGEMUSYA >= (battle_config.WOE_K_DELAY_KG_KAGEMUSYA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_KG_KAGEMUSYA >= (battle_config.K_DELAY_KG_KAGEMUSYA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_KG_KAGEMUSYA = sd->K_LOCK_KG_KAGEMUSYA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_KG_KAGEMUSYA = gettick() + battle_config.WOE_K_DELAY_KG_KAGEMUSYA;
				else
					sd->K_CHK_KG_KAGEMUSYA = gettick() + battle_config.K_DELAY_KG_KAGEMUSYA;

				sd->K_LOCK_KG_KAGEMUSYA = 0;
			}
			break;
		case OB_ZANGETSU:
			if(DIFF_TICK(sd->K_CHK_OB_ZANGETSU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_OB_ZANGETSU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_OB_ZANGETSU >= (battle_config.WOE_K_DELAY_OB_ZANGETSU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_OB_ZANGETSU >= (battle_config.K_DELAY_OB_ZANGETSU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_OB_ZANGETSU = sd->K_LOCK_OB_ZANGETSU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_OB_ZANGETSU = gettick() + battle_config.WOE_K_DELAY_OB_ZANGETSU;
				else
					sd->K_CHK_OB_ZANGETSU = gettick() + battle_config.K_DELAY_OB_ZANGETSU;

				sd->K_LOCK_OB_ZANGETSU = 0;
			}
			break;
		case OB_OBOROGENSOU:
			if(DIFF_TICK(sd->K_CHK_OB_OBOROGENSOU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_OB_OBOROGENSOU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_OB_OBOROGENSOU >= (battle_config.WOE_K_DELAY_OB_OBOROGENSOU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_OB_OBOROGENSOU >= (battle_config.K_DELAY_OB_OBOROGENSOU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_OB_OBOROGENSOU = sd->K_LOCK_OB_OBOROGENSOU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_OB_OBOROGENSOU = gettick() + battle_config.WOE_K_DELAY_OB_OBOROGENSOU;
				else
					sd->K_CHK_OB_OBOROGENSOU = gettick() + battle_config.K_DELAY_OB_OBOROGENSOU;

				sd->K_LOCK_OB_OBOROGENSOU = 0;
			}
			break;
		case OB_OBOROGENSOU_TRANSITION_ATK:
			if(DIFF_TICK(sd->K_CHK_OB_OBOROGENSOU_TRANSITION_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_OB_OBOROGENSOU_TRANSITION_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_OB_OBOROGENSOU_TRANSITION_ATK >= (battle_config.WOE_K_DELAY_OB_OBOROGENSOU_TRANSITION_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_OB_OBOROGENSOU_TRANSITION_ATK >= (battle_config.K_DELAY_OB_OBOROGENSOU_TRANSITION_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_OB_OBOROGENSOU_TRANSITION_ATK = sd->K_LOCK_OB_OBOROGENSOU_TRANSITION_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_OB_OBOROGENSOU_TRANSITION_ATK = gettick() + battle_config.WOE_K_DELAY_OB_OBOROGENSOU_TRANSITION_ATK;
				else
					sd->K_CHK_OB_OBOROGENSOU_TRANSITION_ATK = gettick() + battle_config.K_DELAY_OB_OBOROGENSOU_TRANSITION_ATK;

				sd->K_LOCK_OB_OBOROGENSOU_TRANSITION_ATK = 0;
			}
			break;
		case OB_AKAITSUKI:
			if(DIFF_TICK(sd->K_CHK_OB_AKAITSUKI,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_OB_AKAITSUKI - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_OB_AKAITSUKI >= (battle_config.WOE_K_DELAY_OB_AKAITSUKI/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_OB_AKAITSUKI >= (battle_config.K_DELAY_OB_AKAITSUKI/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_OB_AKAITSUKI = sd->K_LOCK_OB_AKAITSUKI +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_OB_AKAITSUKI = gettick() + battle_config.WOE_K_DELAY_OB_AKAITSUKI;
				else
					sd->K_CHK_OB_AKAITSUKI = gettick() + battle_config.K_DELAY_OB_AKAITSUKI;

				sd->K_LOCK_OB_AKAITSUKI = 0;
			}
			break;
		case GC_DARKCROW:
			if(DIFF_TICK(sd->K_CHK_GC_DARKCROW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GC_DARKCROW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GC_DARKCROW >= (battle_config.WOE_K_DELAY_GC_DARKCROW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GC_DARKCROW >= (battle_config.K_DELAY_GC_DARKCROW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GC_DARKCROW = sd->K_LOCK_GC_DARKCROW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GC_DARKCROW = gettick() + battle_config.WOE_K_DELAY_GC_DARKCROW;
				else
					sd->K_CHK_GC_DARKCROW = gettick() + battle_config.K_DELAY_GC_DARKCROW;

				sd->K_LOCK_GC_DARKCROW = 0;
			}
			break;
		case RA_UNLIMIT:
			if(DIFF_TICK(sd->K_CHK_RA_UNLIMIT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RA_UNLIMIT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RA_UNLIMIT >= (battle_config.WOE_K_DELAY_RA_UNLIMIT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RA_UNLIMIT >= (battle_config.K_DELAY_RA_UNLIMIT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RA_UNLIMIT = sd->K_LOCK_RA_UNLIMIT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RA_UNLIMIT = gettick() + battle_config.WOE_K_DELAY_RA_UNLIMIT;
				else
					sd->K_CHK_RA_UNLIMIT = gettick() + battle_config.K_DELAY_RA_UNLIMIT;

				sd->K_LOCK_RA_UNLIMIT = 0;
			}
			break;
		case GN_ILLUSIONDOPING:
			if(DIFF_TICK(sd->K_CHK_GN_ILLUSIONDOPING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_GN_ILLUSIONDOPING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_GN_ILLUSIONDOPING >= (battle_config.WOE_K_DELAY_GN_ILLUSIONDOPING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_GN_ILLUSIONDOPING >= (battle_config.K_DELAY_GN_ILLUSIONDOPING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_GN_ILLUSIONDOPING = sd->K_LOCK_GN_ILLUSIONDOPING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_GN_ILLUSIONDOPING = gettick() + battle_config.WOE_K_DELAY_GN_ILLUSIONDOPING;
				else
					sd->K_CHK_GN_ILLUSIONDOPING = gettick() + battle_config.K_DELAY_GN_ILLUSIONDOPING;

				sd->K_LOCK_GN_ILLUSIONDOPING = 0;
			}
			break;
		case RK_DRAGONBREATH_WATER:
			if(DIFF_TICK(sd->K_CHK_RK_DRAGONBREATH_WATER,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_DRAGONBREATH_WATER - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_DRAGONBREATH_WATER >= (battle_config.WOE_K_DELAY_RK_DRAGONBREATH_WATER/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_DRAGONBREATH_WATER >= (battle_config.K_DELAY_RK_DRAGONBREATH_WATER/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_DRAGONBREATH_WATER = sd->K_LOCK_RK_DRAGONBREATH_WATER +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_DRAGONBREATH_WATER = gettick() + battle_config.WOE_K_DELAY_RK_DRAGONBREATH_WATER;
				else
					sd->K_CHK_RK_DRAGONBREATH_WATER = gettick() + battle_config.K_DELAY_RK_DRAGONBREATH_WATER;

				sd->K_LOCK_RK_DRAGONBREATH_WATER = 0;
			}
			break;
		case RK_LUXANIMA:
			if(DIFF_TICK(sd->K_CHK_RK_LUXANIMA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_RK_LUXANIMA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_RK_LUXANIMA >= (battle_config.WOE_K_DELAY_RK_LUXANIMA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_RK_LUXANIMA >= (battle_config.K_DELAY_RK_LUXANIMA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_RK_LUXANIMA = sd->K_LOCK_RK_LUXANIMA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_RK_LUXANIMA = gettick() + battle_config.WOE_K_DELAY_RK_LUXANIMA;
				else
					sd->K_CHK_RK_LUXANIMA = gettick() + battle_config.K_DELAY_RK_LUXANIMA;

				sd->K_LOCK_RK_LUXANIMA = 0;
			}
			break;
		case NC_MAGMA_ERUPTION:
			if(DIFF_TICK(sd->K_CHK_NC_MAGMA_ERUPTION,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_NC_MAGMA_ERUPTION - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_NC_MAGMA_ERUPTION >= (battle_config.WOE_K_DELAY_NC_MAGMA_ERUPTION/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_NC_MAGMA_ERUPTION >= (battle_config.K_DELAY_NC_MAGMA_ERUPTION/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_NC_MAGMA_ERUPTION = sd->K_LOCK_NC_MAGMA_ERUPTION +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_NC_MAGMA_ERUPTION = gettick() + battle_config.WOE_K_DELAY_NC_MAGMA_ERUPTION;
				else
					sd->K_CHK_NC_MAGMA_ERUPTION = gettick() + battle_config.K_DELAY_NC_MAGMA_ERUPTION;

				sd->K_LOCK_NC_MAGMA_ERUPTION = 0;
			}
			break;
		case WM_FRIGG_SONG:
			if(DIFF_TICK(sd->K_CHK_WM_FRIGG_SONG,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WM_FRIGG_SONG - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WM_FRIGG_SONG >= (battle_config.WOE_K_DELAY_WM_FRIGG_SONG/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WM_FRIGG_SONG >= (battle_config.K_DELAY_WM_FRIGG_SONG/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WM_FRIGG_SONG = sd->K_LOCK_WM_FRIGG_SONG +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WM_FRIGG_SONG = gettick() + battle_config.WOE_K_DELAY_WM_FRIGG_SONG;
				else
					sd->K_CHK_WM_FRIGG_SONG = gettick() + battle_config.K_DELAY_WM_FRIGG_SONG;

				sd->K_LOCK_WM_FRIGG_SONG = 0;
			}
			break;
		case SO_ELEMENTAL_SHIELD:
			if(DIFF_TICK(sd->K_CHK_SO_ELEMENTAL_SHIELD,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SO_ELEMENTAL_SHIELD - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SO_ELEMENTAL_SHIELD >= (battle_config.WOE_K_DELAY_SO_ELEMENTAL_SHIELD/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SO_ELEMENTAL_SHIELD >= (battle_config.K_DELAY_SO_ELEMENTAL_SHIELD/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SO_ELEMENTAL_SHIELD = sd->K_LOCK_SO_ELEMENTAL_SHIELD +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SO_ELEMENTAL_SHIELD = gettick() + battle_config.WOE_K_DELAY_SO_ELEMENTAL_SHIELD;
				else
					sd->K_CHK_SO_ELEMENTAL_SHIELD = gettick() + battle_config.K_DELAY_SO_ELEMENTAL_SHIELD;

				sd->K_LOCK_SO_ELEMENTAL_SHIELD = 0;
			}
			break;
		case SR_FLASHCOMBO:
			if(DIFF_TICK(sd->K_CHK_SR_FLASHCOMBO,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SR_FLASHCOMBO - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SR_FLASHCOMBO >= (battle_config.WOE_K_DELAY_SR_FLASHCOMBO/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SR_FLASHCOMBO >= (battle_config.K_DELAY_SR_FLASHCOMBO/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SR_FLASHCOMBO = sd->K_LOCK_SR_FLASHCOMBO +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SR_FLASHCOMBO = gettick() + battle_config.WOE_K_DELAY_SR_FLASHCOMBO;
				else
					sd->K_CHK_SR_FLASHCOMBO = gettick() + battle_config.K_DELAY_SR_FLASHCOMBO;

				sd->K_LOCK_SR_FLASHCOMBO = 0;
			}
			break;
		case SC_ESCAPE:
			if(DIFF_TICK(sd->K_CHK_SC_ESCAPE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SC_ESCAPE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SC_ESCAPE >= (battle_config.WOE_K_DELAY_SC_ESCAPE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SC_ESCAPE >= (battle_config.K_DELAY_SC_ESCAPE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SC_ESCAPE = sd->K_LOCK_SC_ESCAPE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SC_ESCAPE = gettick() + battle_config.WOE_K_DELAY_SC_ESCAPE;
				else
					sd->K_CHK_SC_ESCAPE = gettick() + battle_config.K_DELAY_SC_ESCAPE;

				sd->K_LOCK_SC_ESCAPE = 0;
			}
			break;
		case AB_OFFERTORIUM:
			if(DIFF_TICK(sd->K_CHK_AB_OFFERTORIUM,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_AB_OFFERTORIUM - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_AB_OFFERTORIUM >= (battle_config.WOE_K_DELAY_AB_OFFERTORIUM/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_AB_OFFERTORIUM >= (battle_config.K_DELAY_AB_OFFERTORIUM/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_AB_OFFERTORIUM = sd->K_LOCK_AB_OFFERTORIUM +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_AB_OFFERTORIUM = gettick() + battle_config.WOE_K_DELAY_AB_OFFERTORIUM;
				else
					sd->K_CHK_AB_OFFERTORIUM = gettick() + battle_config.K_DELAY_AB_OFFERTORIUM;

				sd->K_LOCK_AB_OFFERTORIUM = 0;
			}
			break;
		case WL_TELEKINESIS_INTENSE:
			if(DIFF_TICK(sd->K_CHK_WL_TELEKINESIS_INTENSE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_WL_TELEKINESIS_INTENSE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_WL_TELEKINESIS_INTENSE >= (battle_config.WOE_K_DELAY_WL_TELEKINESIS_INTENSE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_WL_TELEKINESIS_INTENSE >= (battle_config.K_DELAY_WL_TELEKINESIS_INTENSE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_WL_TELEKINESIS_INTENSE = sd->K_LOCK_WL_TELEKINESIS_INTENSE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_WL_TELEKINESIS_INTENSE = gettick() + battle_config.WOE_K_DELAY_WL_TELEKINESIS_INTENSE;
				else
					sd->K_CHK_WL_TELEKINESIS_INTENSE = gettick() + battle_config.K_DELAY_WL_TELEKINESIS_INTENSE;

				sd->K_LOCK_WL_TELEKINESIS_INTENSE = 0;
			}
			break;
		case ALL_FULL_THROTTLE:
			if(DIFF_TICK(sd->K_CHK_ALL_FULL_THROTTLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_ALL_FULL_THROTTLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_ALL_FULL_THROTTLE >= (battle_config.WOE_K_DELAY_ALL_FULL_THROTTLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_ALL_FULL_THROTTLE >= (battle_config.K_DELAY_ALL_FULL_THROTTLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_ALL_FULL_THROTTLE = sd->K_LOCK_ALL_FULL_THROTTLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_ALL_FULL_THROTTLE = gettick() + battle_config.WOE_K_DELAY_ALL_FULL_THROTTLE;
				else
					sd->K_CHK_ALL_FULL_THROTTLE = gettick() + battle_config.K_DELAY_ALL_FULL_THROTTLE;

				sd->K_LOCK_ALL_FULL_THROTTLE = 0;
			}
			break;
		case SU_BITE:
			if(DIFF_TICK(sd->K_CHK_SU_BITE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_BITE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_BITE >= (battle_config.WOE_K_DELAY_SU_BITE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_BITE >= (battle_config.K_DELAY_SU_BITE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_BITE = sd->K_LOCK_SU_BITE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_BITE = gettick() + battle_config.WOE_K_DELAY_SU_BITE;
				else
					sd->K_CHK_SU_BITE = gettick() + battle_config.K_DELAY_SU_BITE;

				sd->K_LOCK_SU_BITE = 0;
			}
			break;
		case SU_SCRATCH:
			if(DIFF_TICK(sd->K_CHK_SU_SCRATCH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SCRATCH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SCRATCH >= (battle_config.WOE_K_DELAY_SU_SCRATCH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SCRATCH >= (battle_config.K_DELAY_SU_SCRATCH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SCRATCH = sd->K_LOCK_SU_SCRATCH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SCRATCH = gettick() + battle_config.WOE_K_DELAY_SU_SCRATCH;
				else
					sd->K_CHK_SU_SCRATCH = gettick() + battle_config.K_DELAY_SU_SCRATCH;

				sd->K_LOCK_SU_SCRATCH = 0;
			}
			break;
		case SU_STOOP:
			if(DIFF_TICK(sd->K_CHK_SU_STOOP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_STOOP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_STOOP >= (battle_config.WOE_K_DELAY_SU_STOOP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_STOOP >= (battle_config.K_DELAY_SU_STOOP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_STOOP = sd->K_LOCK_SU_STOOP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_STOOP = gettick() + battle_config.WOE_K_DELAY_SU_STOOP;
				else
					sd->K_CHK_SU_STOOP = gettick() + battle_config.K_DELAY_SU_STOOP;

				sd->K_LOCK_SU_STOOP = 0;
			}
			break;
		case SU_LOPE:
			if(DIFF_TICK(sd->K_CHK_SU_LOPE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_LOPE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_LOPE >= (battle_config.WOE_K_DELAY_SU_LOPE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_LOPE >= (battle_config.K_DELAY_SU_LOPE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_LOPE = sd->K_LOCK_SU_LOPE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_LOPE = gettick() + battle_config.WOE_K_DELAY_SU_LOPE;
				else
					sd->K_CHK_SU_LOPE = gettick() + battle_config.K_DELAY_SU_LOPE;

				sd->K_LOCK_SU_LOPE = 0;
			}
			break;
		case SU_SPRITEMABLE:
			if(DIFF_TICK(sd->K_CHK_SU_SPRITEMABLE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SPRITEMABLE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SPRITEMABLE >= (battle_config.WOE_K_DELAY_SU_SPRITEMABLE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SPRITEMABLE >= (battle_config.K_DELAY_SU_SPRITEMABLE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SPRITEMABLE = sd->K_LOCK_SU_SPRITEMABLE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SPRITEMABLE = gettick() + battle_config.WOE_K_DELAY_SU_SPRITEMABLE;
				else
					sd->K_CHK_SU_SPRITEMABLE = gettick() + battle_config.K_DELAY_SU_SPRITEMABLE;

				sd->K_LOCK_SU_SPRITEMABLE = 0;
			}
			break;
		case SU_POWEROFLAND:
			if(DIFF_TICK(sd->K_CHK_SU_POWEROFLAND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_POWEROFLAND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_POWEROFLAND >= (battle_config.WOE_K_DELAY_SU_POWEROFLAND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_POWEROFLAND >= (battle_config.K_DELAY_SU_POWEROFLAND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_POWEROFLAND = sd->K_LOCK_SU_POWEROFLAND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_POWEROFLAND = gettick() + battle_config.WOE_K_DELAY_SU_POWEROFLAND;
				else
					sd->K_CHK_SU_POWEROFLAND = gettick() + battle_config.K_DELAY_SU_POWEROFLAND;

				sd->K_LOCK_SU_POWEROFLAND = 0;
			}
			break;
		case SU_SV_STEMSPEAR:
			if(DIFF_TICK(sd->K_CHK_SU_SV_STEMSPEAR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SV_STEMSPEAR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SV_STEMSPEAR >= (battle_config.WOE_K_DELAY_SU_SV_STEMSPEAR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SV_STEMSPEAR >= (battle_config.K_DELAY_SU_SV_STEMSPEAR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SV_STEMSPEAR = sd->K_LOCK_SU_SV_STEMSPEAR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SV_STEMSPEAR = gettick() + battle_config.WOE_K_DELAY_SU_SV_STEMSPEAR;
				else
					sd->K_CHK_SU_SV_STEMSPEAR = gettick() + battle_config.K_DELAY_SU_SV_STEMSPEAR;

				sd->K_LOCK_SU_SV_STEMSPEAR = 0;
			}
			break;
		case SU_CN_POWDERING:
			if(DIFF_TICK(sd->K_CHK_SU_CN_POWDERING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_CN_POWDERING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_CN_POWDERING >= (battle_config.WOE_K_DELAY_SU_CN_POWDERING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_CN_POWDERING >= (battle_config.K_DELAY_SU_CN_POWDERING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_CN_POWDERING = sd->K_LOCK_SU_CN_POWDERING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_CN_POWDERING = gettick() + battle_config.WOE_K_DELAY_SU_CN_POWDERING;
				else
					sd->K_CHK_SU_CN_POWDERING = gettick() + battle_config.K_DELAY_SU_CN_POWDERING;

				sd->K_LOCK_SU_CN_POWDERING = 0;
			}
			break;
		case SU_CN_METEOR:
			if(DIFF_TICK(sd->K_CHK_SU_CN_METEOR,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_CN_METEOR - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_CN_METEOR >= (battle_config.WOE_K_DELAY_SU_CN_METEOR/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_CN_METEOR >= (battle_config.K_DELAY_SU_CN_METEOR/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_CN_METEOR = sd->K_LOCK_SU_CN_METEOR +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_CN_METEOR = gettick() + battle_config.WOE_K_DELAY_SU_CN_METEOR;
				else
					sd->K_CHK_SU_CN_METEOR = gettick() + battle_config.K_DELAY_SU_CN_METEOR;

				sd->K_LOCK_SU_CN_METEOR = 0;
			}
			break;
		case SU_SV_ROOTTWIST:
			if(DIFF_TICK(sd->K_CHK_SU_SV_ROOTTWIST,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SV_ROOTTWIST - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SV_ROOTTWIST >= (battle_config.WOE_K_DELAY_SU_SV_ROOTTWIST/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SV_ROOTTWIST >= (battle_config.K_DELAY_SU_SV_ROOTTWIST/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SV_ROOTTWIST = sd->K_LOCK_SU_SV_ROOTTWIST +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SV_ROOTTWIST = gettick() + battle_config.WOE_K_DELAY_SU_SV_ROOTTWIST;
				else
					sd->K_CHK_SU_SV_ROOTTWIST = gettick() + battle_config.K_DELAY_SU_SV_ROOTTWIST;

				sd->K_LOCK_SU_SV_ROOTTWIST = 0;
			}
			break;
		case SU_SV_ROOTTWIST_ATK:
			if(DIFF_TICK(sd->K_CHK_SU_SV_ROOTTWIST_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SV_ROOTTWIST_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SV_ROOTTWIST_ATK >= (battle_config.WOE_K_DELAY_SU_SV_ROOTTWIST_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SV_ROOTTWIST_ATK >= (battle_config.K_DELAY_SU_SV_ROOTTWIST_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SV_ROOTTWIST_ATK = sd->K_LOCK_SU_SV_ROOTTWIST_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SV_ROOTTWIST_ATK = gettick() + battle_config.WOE_K_DELAY_SU_SV_ROOTTWIST_ATK;
				else
					sd->K_CHK_SU_SV_ROOTTWIST_ATK = gettick() + battle_config.K_DELAY_SU_SV_ROOTTWIST_ATK;

				sd->K_LOCK_SU_SV_ROOTTWIST_ATK = 0;
			}
			break;
		case SU_POWEROFLIFE:
			if(DIFF_TICK(sd->K_CHK_SU_POWEROFLIFE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_POWEROFLIFE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_POWEROFLIFE >= (battle_config.WOE_K_DELAY_SU_POWEROFLIFE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_POWEROFLIFE >= (battle_config.K_DELAY_SU_POWEROFLIFE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_POWEROFLIFE = sd->K_LOCK_SU_POWEROFLIFE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_POWEROFLIFE = gettick() + battle_config.WOE_K_DELAY_SU_POWEROFLIFE;
				else
					sd->K_CHK_SU_POWEROFLIFE = gettick() + battle_config.K_DELAY_SU_POWEROFLIFE;

				sd->K_LOCK_SU_POWEROFLIFE = 0;
			}
			break;
		case SU_SCAROFTAROU:
			if(DIFF_TICK(sd->K_CHK_SU_SCAROFTAROU,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SCAROFTAROU - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SCAROFTAROU >= (battle_config.WOE_K_DELAY_SU_SCAROFTAROU/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SCAROFTAROU >= (battle_config.K_DELAY_SU_SCAROFTAROU/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SCAROFTAROU = sd->K_LOCK_SU_SCAROFTAROU +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SCAROFTAROU = gettick() + battle_config.WOE_K_DELAY_SU_SCAROFTAROU;
				else
					sd->K_CHK_SU_SCAROFTAROU = gettick() + battle_config.K_DELAY_SU_SCAROFTAROU;

				sd->K_LOCK_SU_SCAROFTAROU = 0;
			}
			break;
		case SU_PICKYPECK:
			if(DIFF_TICK(sd->K_CHK_SU_PICKYPECK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_PICKYPECK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_PICKYPECK >= (battle_config.WOE_K_DELAY_SU_PICKYPECK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_PICKYPECK >= (battle_config.K_DELAY_SU_PICKYPECK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_PICKYPECK = sd->K_LOCK_SU_PICKYPECK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_PICKYPECK = gettick() + battle_config.WOE_K_DELAY_SU_PICKYPECK;
				else
					sd->K_CHK_SU_PICKYPECK = gettick() + battle_config.K_DELAY_SU_PICKYPECK;

				sd->K_LOCK_SU_PICKYPECK = 0;
			}
			break;
		case SU_PICKYPECK_DOUBLE_ATK:
			if(DIFF_TICK(sd->K_CHK_SU_PICKYPECK_DOUBLE_ATK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_PICKYPECK_DOUBLE_ATK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_PICKYPECK_DOUBLE_ATK >= (battle_config.WOE_K_DELAY_SU_PICKYPECK_DOUBLE_ATK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_PICKYPECK_DOUBLE_ATK >= (battle_config.K_DELAY_SU_PICKYPECK_DOUBLE_ATK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_PICKYPECK_DOUBLE_ATK = sd->K_LOCK_SU_PICKYPECK_DOUBLE_ATK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_PICKYPECK_DOUBLE_ATK = gettick() + battle_config.WOE_K_DELAY_SU_PICKYPECK_DOUBLE_ATK;
				else
					sd->K_CHK_SU_PICKYPECK_DOUBLE_ATK = gettick() + battle_config.K_DELAY_SU_PICKYPECK_DOUBLE_ATK;

				sd->K_LOCK_SU_PICKYPECK_DOUBLE_ATK = 0;
			}
			break;
		case SU_ARCLOUSEDASH:
			if(DIFF_TICK(sd->K_CHK_SU_ARCLOUSEDASH,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_ARCLOUSEDASH - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_ARCLOUSEDASH >= (battle_config.WOE_K_DELAY_SU_ARCLOUSEDASH/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_ARCLOUSEDASH >= (battle_config.K_DELAY_SU_ARCLOUSEDASH/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_ARCLOUSEDASH = sd->K_LOCK_SU_ARCLOUSEDASH +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_ARCLOUSEDASH = gettick() + battle_config.WOE_K_DELAY_SU_ARCLOUSEDASH;
				else
					sd->K_CHK_SU_ARCLOUSEDASH = gettick() + battle_config.K_DELAY_SU_ARCLOUSEDASH;

				sd->K_LOCK_SU_ARCLOUSEDASH = 0;
			}
			break;
		case SU_LUNATICCARROTBEAT:
			if(DIFF_TICK(sd->K_CHK_SU_LUNATICCARROTBEAT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_LUNATICCARROTBEAT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_LUNATICCARROTBEAT >= (battle_config.WOE_K_DELAY_SU_LUNATICCARROTBEAT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_LUNATICCARROTBEAT >= (battle_config.K_DELAY_SU_LUNATICCARROTBEAT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_LUNATICCARROTBEAT = sd->K_LOCK_SU_LUNATICCARROTBEAT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_LUNATICCARROTBEAT = gettick() + battle_config.WOE_K_DELAY_SU_LUNATICCARROTBEAT;
				else
					sd->K_CHK_SU_LUNATICCARROTBEAT = gettick() + battle_config.K_DELAY_SU_LUNATICCARROTBEAT;

				sd->K_LOCK_SU_LUNATICCARROTBEAT = 0;
			}
			break;
		case SU_POWEROFSEA:
			if(DIFF_TICK(sd->K_CHK_SU_POWEROFSEA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_POWEROFSEA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_POWEROFSEA >= (battle_config.WOE_K_DELAY_SU_POWEROFSEA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_POWEROFSEA >= (battle_config.K_DELAY_SU_POWEROFSEA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_POWEROFSEA = sd->K_LOCK_SU_POWEROFSEA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_POWEROFSEA = gettick() + battle_config.WOE_K_DELAY_SU_POWEROFSEA;
				else
					sd->K_CHK_SU_POWEROFSEA = gettick() + battle_config.K_DELAY_SU_POWEROFSEA;

				sd->K_LOCK_SU_POWEROFSEA = 0;
			}
			break;
		case SU_TUNABELLY:
			if(DIFF_TICK(sd->K_CHK_SU_TUNABELLY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_TUNABELLY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_TUNABELLY >= (battle_config.WOE_K_DELAY_SU_TUNABELLY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_TUNABELLY >= (battle_config.K_DELAY_SU_TUNABELLY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_TUNABELLY = sd->K_LOCK_SU_TUNABELLY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_TUNABELLY = gettick() + battle_config.WOE_K_DELAY_SU_TUNABELLY;
				else
					sd->K_CHK_SU_TUNABELLY = gettick() + battle_config.K_DELAY_SU_TUNABELLY;

				sd->K_LOCK_SU_TUNABELLY = 0;
			}
			break;
		case SU_TUNAPARTY:
			if(DIFF_TICK(sd->K_CHK_SU_TUNAPARTY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_TUNAPARTY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_TUNAPARTY >= (battle_config.WOE_K_DELAY_SU_TUNAPARTY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_TUNAPARTY >= (battle_config.K_DELAY_SU_TUNAPARTY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_TUNAPARTY = sd->K_LOCK_SU_TUNAPARTY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_TUNAPARTY = gettick() + battle_config.WOE_K_DELAY_SU_TUNAPARTY;
				else
					sd->K_CHK_SU_TUNAPARTY = gettick() + battle_config.K_DELAY_SU_TUNAPARTY;

				sd->K_LOCK_SU_TUNAPARTY = 0;
			}
			break;
		case SU_BUNCHOFSHRIMP:
			if(DIFF_TICK(sd->K_CHK_SU_BUNCHOFSHRIMP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_BUNCHOFSHRIMP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_BUNCHOFSHRIMP >= (battle_config.WOE_K_DELAY_SU_BUNCHOFSHRIMP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_BUNCHOFSHRIMP >= (battle_config.K_DELAY_SU_BUNCHOFSHRIMP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_BUNCHOFSHRIMP = sd->K_LOCK_SU_BUNCHOFSHRIMP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_BUNCHOFSHRIMP = gettick() + battle_config.WOE_K_DELAY_SU_BUNCHOFSHRIMP;
				else
					sd->K_CHK_SU_BUNCHOFSHRIMP = gettick() + battle_config.K_DELAY_SU_BUNCHOFSHRIMP;

				sd->K_LOCK_SU_BUNCHOFSHRIMP = 0;
			}
			break;
		case SU_FRESHSHRIMP:
			if(DIFF_TICK(sd->K_CHK_SU_FRESHSHRIMP,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_FRESHSHRIMP - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_FRESHSHRIMP >= (battle_config.WOE_K_DELAY_SU_FRESHSHRIMP/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_FRESHSHRIMP >= (battle_config.K_DELAY_SU_FRESHSHRIMP/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_FRESHSHRIMP = sd->K_LOCK_SU_FRESHSHRIMP +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_FRESHSHRIMP = gettick() + battle_config.WOE_K_DELAY_SU_FRESHSHRIMP;
				else
					sd->K_CHK_SU_FRESHSHRIMP = gettick() + battle_config.K_DELAY_SU_FRESHSHRIMP;

				sd->K_LOCK_SU_FRESHSHRIMP = 0;
			}
			break;
		case SU_CN_METEOR2:
			if(DIFF_TICK(sd->K_CHK_SU_CN_METEOR2,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_CN_METEOR2 - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_CN_METEOR2 >= (battle_config.WOE_K_DELAY_SU_CN_METEOR2/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_CN_METEOR2 >= (battle_config.K_DELAY_SU_CN_METEOR2/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_CN_METEOR2 = sd->K_LOCK_SU_CN_METEOR2 +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_CN_METEOR2 = gettick() + battle_config.WOE_K_DELAY_SU_CN_METEOR2;
				else
					sd->K_CHK_SU_CN_METEOR2 = gettick() + battle_config.K_DELAY_SU_CN_METEOR2;

				sd->K_LOCK_SU_CN_METEOR2 = 0;
			}
			break;
		case SU_LUNATICCARROTBEAT2:
			if(DIFF_TICK(sd->K_CHK_SU_LUNATICCARROTBEAT2,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_LUNATICCARROTBEAT2 - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_LUNATICCARROTBEAT2 >= (battle_config.WOE_K_DELAY_SU_LUNATICCARROTBEAT2/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_LUNATICCARROTBEAT2 >= (battle_config.K_DELAY_SU_LUNATICCARROTBEAT2/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_LUNATICCARROTBEAT2 = sd->K_LOCK_SU_LUNATICCARROTBEAT2 +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_LUNATICCARROTBEAT2 = gettick() + battle_config.WOE_K_DELAY_SU_LUNATICCARROTBEAT2;
				else
					sd->K_CHK_SU_LUNATICCARROTBEAT2 = gettick() + battle_config.K_DELAY_SU_LUNATICCARROTBEAT2;

				sd->K_LOCK_SU_LUNATICCARROTBEAT2 = 0;
			}
			break;
		case SU_SOULATTACK:
			if(DIFF_TICK(sd->K_CHK_SU_SOULATTACK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SOULATTACK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SOULATTACK >= (battle_config.WOE_K_DELAY_SU_SOULATTACK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SOULATTACK >= (battle_config.K_DELAY_SU_SOULATTACK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SOULATTACK = sd->K_LOCK_SU_SOULATTACK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SOULATTACK = gettick() + battle_config.WOE_K_DELAY_SU_SOULATTACK;
				else
					sd->K_CHK_SU_SOULATTACK = gettick() + battle_config.K_DELAY_SU_SOULATTACK;

				sd->K_LOCK_SU_SOULATTACK = 0;
			}
			break;
		case SU_POWEROFFLOCK:
			if(DIFF_TICK(sd->K_CHK_SU_POWEROFFLOCK,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_POWEROFFLOCK - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_POWEROFFLOCK >= (battle_config.WOE_K_DELAY_SU_POWEROFFLOCK/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_POWEROFFLOCK >= (battle_config.K_DELAY_SU_POWEROFFLOCK/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_POWEROFFLOCK = sd->K_LOCK_SU_POWEROFFLOCK +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_POWEROFFLOCK = gettick() + battle_config.WOE_K_DELAY_SU_POWEROFFLOCK;
				else
					sd->K_CHK_SU_POWEROFFLOCK = gettick() + battle_config.K_DELAY_SU_POWEROFFLOCK;

				sd->K_LOCK_SU_POWEROFFLOCK = 0;
			}
			break;
		case SU_SVG_SPIRIT:
			if(DIFF_TICK(sd->K_CHK_SU_SVG_SPIRIT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SVG_SPIRIT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SVG_SPIRIT >= (battle_config.WOE_K_DELAY_SU_SVG_SPIRIT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SVG_SPIRIT >= (battle_config.K_DELAY_SU_SVG_SPIRIT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SVG_SPIRIT = sd->K_LOCK_SU_SVG_SPIRIT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SVG_SPIRIT = gettick() + battle_config.WOE_K_DELAY_SU_SVG_SPIRIT;
				else
					sd->K_CHK_SU_SVG_SPIRIT = gettick() + battle_config.K_DELAY_SU_SVG_SPIRIT;

				sd->K_LOCK_SU_SVG_SPIRIT = 0;
			}
			break;
		case SU_HISS:
			if(DIFF_TICK(sd->K_CHK_SU_HISS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_HISS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_HISS >= (battle_config.WOE_K_DELAY_SU_HISS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_HISS >= (battle_config.K_DELAY_SU_HISS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_HISS = sd->K_LOCK_SU_HISS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_HISS = gettick() + battle_config.WOE_K_DELAY_SU_HISS;
				else
					sd->K_CHK_SU_HISS = gettick() + battle_config.K_DELAY_SU_HISS;

				sd->K_LOCK_SU_HISS = 0;
			}
			break;
		case SU_NYANGGRASS:
			if(DIFF_TICK(sd->K_CHK_SU_NYANGGRASS,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_NYANGGRASS - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_NYANGGRASS >= (battle_config.WOE_K_DELAY_SU_NYANGGRASS/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_NYANGGRASS >= (battle_config.K_DELAY_SU_NYANGGRASS/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_NYANGGRASS = sd->K_LOCK_SU_NYANGGRASS +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_NYANGGRASS = gettick() + battle_config.WOE_K_DELAY_SU_NYANGGRASS;
				else
					sd->K_CHK_SU_NYANGGRASS = gettick() + battle_config.K_DELAY_SU_NYANGGRASS;

				sd->K_LOCK_SU_NYANGGRASS = 0;
			}
			break;
		case SU_GROOMING:
			if(DIFF_TICK(sd->K_CHK_SU_GROOMING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_GROOMING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_GROOMING >= (battle_config.WOE_K_DELAY_SU_GROOMING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_GROOMING >= (battle_config.K_DELAY_SU_GROOMING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_GROOMING = sd->K_LOCK_SU_GROOMING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_GROOMING = gettick() + battle_config.WOE_K_DELAY_SU_GROOMING;
				else
					sd->K_CHK_SU_GROOMING = gettick() + battle_config.K_DELAY_SU_GROOMING;

				sd->K_LOCK_SU_GROOMING = 0;
			}
			break;
		case SU_PURRING:
			if(DIFF_TICK(sd->K_CHK_SU_PURRING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_PURRING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_PURRING >= (battle_config.WOE_K_DELAY_SU_PURRING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_PURRING >= (battle_config.K_DELAY_SU_PURRING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_PURRING = sd->K_LOCK_SU_PURRING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_PURRING = gettick() + battle_config.WOE_K_DELAY_SU_PURRING;
				else
					sd->K_CHK_SU_PURRING = gettick() + battle_config.K_DELAY_SU_PURRING;

				sd->K_LOCK_SU_PURRING = 0;
			}
			break;
		case SU_SHRIMPARTY:
			if(DIFF_TICK(sd->K_CHK_SU_SHRIMPARTY,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SHRIMPARTY - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SHRIMPARTY >= (battle_config.WOE_K_DELAY_SU_SHRIMPARTY/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SHRIMPARTY >= (battle_config.K_DELAY_SU_SHRIMPARTY/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SHRIMPARTY = sd->K_LOCK_SU_SHRIMPARTY +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SHRIMPARTY = gettick() + battle_config.WOE_K_DELAY_SU_SHRIMPARTY;
				else
					sd->K_CHK_SU_SHRIMPARTY = gettick() + battle_config.K_DELAY_SU_SHRIMPARTY;

				sd->K_LOCK_SU_SHRIMPARTY = 0;
			}
			break;
		case SU_SPIRITOFLIFE:
			if(DIFF_TICK(sd->K_CHK_SU_SPIRITOFLIFE,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SPIRITOFLIFE - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SPIRITOFLIFE >= (battle_config.WOE_K_DELAY_SU_SPIRITOFLIFE/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SPIRITOFLIFE >= (battle_config.K_DELAY_SU_SPIRITOFLIFE/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SPIRITOFLIFE = sd->K_LOCK_SU_SPIRITOFLIFE +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SPIRITOFLIFE = gettick() + battle_config.WOE_K_DELAY_SU_SPIRITOFLIFE;
				else
					sd->K_CHK_SU_SPIRITOFLIFE = gettick() + battle_config.K_DELAY_SU_SPIRITOFLIFE;

				sd->K_LOCK_SU_SPIRITOFLIFE = 0;
			}
			break;
		case SU_MEOWMEOW:
			if(DIFF_TICK(sd->K_CHK_SU_MEOWMEOW,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_MEOWMEOW - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_MEOWMEOW >= (battle_config.WOE_K_DELAY_SU_MEOWMEOW/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_MEOWMEOW >= (battle_config.K_DELAY_SU_MEOWMEOW/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_MEOWMEOW = sd->K_LOCK_SU_MEOWMEOW +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_MEOWMEOW = gettick() + battle_config.WOE_K_DELAY_SU_MEOWMEOW;
				else
					sd->K_CHK_SU_MEOWMEOW = gettick() + battle_config.K_DELAY_SU_MEOWMEOW;

				sd->K_LOCK_SU_MEOWMEOW = 0;
			}
			break;
		case SU_SPIRITOFLAND:
			if(DIFF_TICK(sd->K_CHK_SU_SPIRITOFLAND,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SPIRITOFLAND - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SPIRITOFLAND >= (battle_config.WOE_K_DELAY_SU_SPIRITOFLAND/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SPIRITOFLAND >= (battle_config.K_DELAY_SU_SPIRITOFLAND/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SPIRITOFLAND = sd->K_LOCK_SU_SPIRITOFLAND +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SPIRITOFLAND = gettick() + battle_config.WOE_K_DELAY_SU_SPIRITOFLAND;
				else
					sd->K_CHK_SU_SPIRITOFLAND = gettick() + battle_config.K_DELAY_SU_SPIRITOFLAND;

				sd->K_LOCK_SU_SPIRITOFLAND = 0;
			}
			break;
		case SU_CHATTERING:
			if(DIFF_TICK(sd->K_CHK_SU_CHATTERING,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_CHATTERING - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_CHATTERING >= (battle_config.WOE_K_DELAY_SU_CHATTERING/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_CHATTERING >= (battle_config.K_DELAY_SU_CHATTERING/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_CHATTERING = sd->K_LOCK_SU_CHATTERING +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_CHATTERING = gettick() + battle_config.WOE_K_DELAY_SU_CHATTERING;
				else
					sd->K_CHK_SU_CHATTERING = gettick() + battle_config.K_DELAY_SU_CHATTERING;

				sd->K_LOCK_SU_CHATTERING = 0;
			}
			break;
		case SU_SPIRITOFSEA:
			if(DIFF_TICK(sd->K_CHK_SU_SPIRITOFSEA,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_SU_SPIRITOFSEA - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_SU_SPIRITOFSEA >= (battle_config.WOE_K_DELAY_SU_SPIRITOFSEA/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_SU_SPIRITOFSEA >= (battle_config.K_DELAY_SU_SPIRITOFSEA/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_SU_SPIRITOFSEA = sd->K_LOCK_SU_SPIRITOFSEA +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_SU_SPIRITOFSEA = gettick() + battle_config.WOE_K_DELAY_SU_SPIRITOFSEA;
				else
					sd->K_CHK_SU_SPIRITOFSEA = gettick() + battle_config.K_DELAY_SU_SPIRITOFSEA;

				sd->K_LOCK_SU_SPIRITOFSEA = 0;
			}
			break;



		default:
			if(DIFF_TICK(sd->K_CHK_DEFAULT,gettick())> 0){
				if(show_delay){
					sprintf(message_skdelay,"[ %i ] second(s) skill use delay",(sd->K_CHK_DEFAULT - gettick())/k);
					clif_messagecolor(&sd->bl,color_table[COLOR_LIGHT_GREEN],message_skdelay,false,SELF);
				}
				if((mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE]) && (sd->K_LOCK_DEFAULT >= (battle_config.WOE_K_DELAY_DEFAULT/Acceptable_Packet)))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player
				else if(sd->K_LOCK_DEFAULT >= (battle_config.K_DELAY_DEFAULT/Acceptable_Packet))
					clif_authfail_fd(sd->fd, 9); // Disconnect Player

				sd->K_LOCK_DEFAULT = sd->K_LOCK_DEFAULT +1;
			}
			else
			{
				if(mapdata->flag[MF_GVG_CASTLE] || mapdata->flag[MF_GVG_TE_CASTLE])
					sd->K_CHK_DEFAULT = gettick() + battle_config.WOE_K_DELAY_DEFAULT;
				else
					sd->K_CHK_DEFAULT = gettick() + battle_config.K_DELAY_DEFAULT;

				sd->K_LOCK_DEFAULT = 0;
			}
			break;
	}
	return 1;
}
