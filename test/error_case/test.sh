FLG=1

echo "--- 引数なし ---"
$REPO_ROOT/so_long
FLG=$(($FLG & $?))

echo "--- 引数が多い ---"
$REPO_ROOT/so_long "test/map/correct_case/1_min.ber" "test/map/correct_case/1_min.ber"
FLG=$(($FLG & $?))

echo "--- 引数が空文字 ---"
$REPO_ROOT/so_long ""
FLG=$(($FLG & $?))

echo "--- 引数が存在しない ---"
$REPO_ROOT/so_long "test/map/notexist.ber"
FLG=$(($FLG & $?))

echo "--- 引数が.berじゃない ---"
$REPO_ROOT/so_long "test/map/correct_case/1_min"
FLG=$(($FLG & $?))

if [ $FLG -eq 1 ]; then
	printf "\e[32m%s\n\e[m" ">> OK!"
else
	printf "\e[31m%s\n\e[m" ">> KO!"
fi

exit $((!$FLG))
