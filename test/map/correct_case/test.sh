FLG=0
DIR=${0%/*.sh}
for path in $(find "$DIR" -type f -name "*.ber" | sort -n -t "/" -k 5);
do
	echo --- `basename "$path"` ---
	$REPO_ROOT/so_long $"$path" &
	sleep 0.5
	kill $!
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
done
exit $FLG
