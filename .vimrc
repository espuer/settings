" Search related settings
set ignorecase          " searches are case insensitive.
set incsearch           " search as characters are entered
set hlsearch            " highlight matches
nnoremap <leader><space> :nohlsearch<CR> " turn off search highlight


" when you past something, pree this key to toggle auto indenting feature
set pastetoggle=<F3>


let mapleader = ','     " Set the leader

" Encoding stuff
set encoding=utf8

" Visual stuff
" colorscheme scheakur
set number              " Set line number
" set numberwidth=5
set cursorline          " highlight current line
set showmatch           " highlight matching [{()}]

syntax enable           " Enable syntax highlighting

" Tab related settings
set expandtab           " tabs are spaces
set softtabstop=2       " number of spaces in tab when editing
set tabstop=2           " number of visual spaces per TAB
set smartindent
set shiftwidth=2

" Misc set visualbell    " stop that ANNOYING beeping

" Display extra whitespace
set list listchars=tab:»·,trail:·,nbsp:·

" Key map for windows shifting
map F  <C-w>l
map D  <C-w>h

" color schme
colorscheme wombat256
:set term=screen-256color
