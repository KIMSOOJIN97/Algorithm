Last login: Sat Aug  1 04:56:54 on console

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
gimsujin-ui-MacBookPro:~ kimsoojin$ ls
Applications
Desktop
Documents
Downloads
Dropbox
Library
Movies
Music
Parallels
Pictures
Public
SW_project
sooojin
~$ 디지털필터.docx
~$8 line.docx
gimsujin-ui-MacBookPro:~ kimsoojin$ cd Applications/
gimsujin-ui-MacBookPro:Applications kimsoojin$ ls
Chrome Apps.localized	iTerm.app
gimsujin-ui-MacBookPro:Applications kimsoojin$ cd -
/Users/kimsoojin
gimsujin-ui-MacBookPro:~ kimsoojin$ ls
Applications
Desktop
Documents
Downloads
Dropbox
Library
Movies
Music
Parallels
        else{
            if(tmp[3][6] != tmp[2][2]){
                rotate(3,dir*-1);
                flag =1;
            }
            else    flag =0;

            if(flag && tmp[2][6] != tmp[1][2])  rotate(2,dir);
            else flag =0;

            if(flag && tmp[1][6] != tmp[0][2])  rotate(1,dir*-1);
        }
    }

    int score =0;
    if(num[0][0])   score += 1;
    if(num[1][0])   score +=2;
    if(num[2][0])   score +=4;
    if(num[3][0])   score +=8;

    cout << score;
    return 0;
}


