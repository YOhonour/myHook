cmd_/home/lyu/桌面/C/myHook/Module.symvers := sed 's/ko$$/o/' /home/lyu/桌面/C/myHook/modules.order | scripts/mod/modpost -m -a   -o /home/lyu/桌面/C/myHook/Module.symvers -e -i Module.symvers   -T -
